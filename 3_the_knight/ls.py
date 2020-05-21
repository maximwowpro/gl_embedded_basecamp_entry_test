#!/bin/python3

import os, stat, datetime
import grp, pwd
import math
import argparse

# function took from: https://stackoverflow.com/a/14822210/11613135
def convert_size(size_bytes):
   if size_bytes == 0:
       return "0B"
   size_name = ("B", "KB", "MB", "GB", "TB", "PB", "EB", "ZB", "YB")
   i = int(math.floor(math.log(size_bytes, 1024)))
   p = math.pow(1024, i)
   s = round(size_bytes / p, 2)
   return "%s %s" % (s, size_name[i])

my_parser = argparse.ArgumentParser(add_help=False)
my_parser.add_argument('-a', action='store_true', default=False)
my_parser.add_argument('-l', action='store_true', default=False)
my_parser.add_argument('-h', action='store_true', default=False)
args = my_parser.parse_args()

files = os.scandir() 

output = [0]

for entry in files : 
    if entry.is_dir() or entry.is_file():
        stat_res = entry.stat()
        output[0] += stat_res.st_size
        name = entry.name
        if False == args.a and "." == name[0]:
                continue
        if False == args.l:
                result = str(name)
                output.append(result)
                continue
        if True == args.h:
                size = convert_size(stat_res.st_size)
        else:
                size = stat_res.st_size
        permissions = stat.filemode(stat_res.st_mode)
        links_inside_dir = stat_res.st_nlink
        owner_gr = grp.getgrgid(stat_res.st_gid).gr_name
        owner_user = pwd.getpwuid(stat_res.st_uid).pw_name
        date = datetime.datetime.fromtimestamp(os.path.getmtime("./"+str(name)))
        
        result = str(permissions) + " " + str(links_inside_dir) + "\t" + str(owner_gr) + "\t" + str(owner_user) + "\t" + str(size) + "\t" + str(date.strftime("%b")) + "\t" + str(date.strftime("%d")) + "\t"
        if date.year == datetime.datetime.now().year:
                result += (str(str(date.hour) + ":" + str(date.minute)))
        else:
                result += (str(date.year))
        
        result += "\t" + str(name)
        output.append([name, result.expandtabs(10)])

output[1:] = sorted(output[1:])

if True == args.l:
        if True == args.h:
                output[0] = "total " + convert_size(output[0])
        else:
                output[0] = "total " + str(output[0])
        print(output[0])
        for i in range(1, len(output)):
                print(output[i][1])
else:
        print(*output[1:], sep=' ')
        
files.close() 

#!/bin/bash

echo "OPERATING SYSTEM"

echo "Operating system name:"
uname -o

echo "Kernel release:"
uname -r

echo "Kernel version:"
uname -v

echo "Top 10 CPU consuming processes:"
ps -eo pid,ppid,cmd,%cpu --sort=-%cpu | head -n 11

echo "Top 10 memory consuming processes:"
ps -eo pid,ppid,cmd,%mem --sort=-%mem | head -n 11

echo "User login information"
echo "Current logged in user:"
whoami

echo "Login name:"
logname

echo "Completed"

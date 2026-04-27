#!/bin/bash

echo "==========================================="
echo "        OPERATING SYSTEM DETAILS           "
echo "==========================================="

echo "Operating System Name:"
uname -o

echo "Kernel Release:"
uname -r

echo "Kernel Version:"
uname -v

echo ""
echo "==========================================="
echo "   TOP 10 CPU CONSUMING PROCESSES          "
echo "==========================================="

ps -eo pid,ppid,cmd,%mem,%cpu --sort=-%cpu | head -n 11

echo ""
echo "==========================================="
echo "   TOP 10 MEMORY CONSUMING PROCESSES       "
echo "==========================================="

ps -eo pid,ppid,cmd,%mem --sort=-%mem | head -n 11

echo ""
echo "==========================================="
echo "        USER LOGIN INFORMATION             "
echo "==========================================="

echo "Current Logged-in User:"
whoami

echo "Login Name:"
logname

echo "==========================================="
echo "     SCRIPT EXECUTION COMPLETED            "
echo "==========================================="

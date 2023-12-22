#!bin/bash

#sys_info
ARCHITECTURE=$(uname -a)
PHYSICAL_CPU=$(lscpu | grep "Socket(s)" | awk '{print $2}')
VIRTUAL_CPU=$(nproc)
MEMORY_USAGE=$(free -m | awk 'NR==2{printf "%s/%sMB (%.2f%%)\n", $3, $2, $3*100/$2}')
DISK_USAGE=$(df -h / | awk 'NR==2{printf "%s/%s (%s)\n", $3, $2, $5}')
CPU_LOAD=$(top -bn1 | grep "Cpu(s)" | awk '{print $2}' | cut -d "%" -f1)
LAST_BOOT=$(who -b | awk '{print $3, $4}')
LVM_STATUS=$(lsblk | grep "lvm" | wc -l)
ACTIVE_CONNECTIONS=$(netstat -ant | grep ESTABLISHED | wc -l)
USER_COUNT=$(who -q | wc -l)
IP_ADDRESS=$(hostname -I | awk '{print $1}')
MAC_ADDRESS=$(ip link show | awk '/ether/ {print $2}' | head -n 1)
SUDO_COMMANDS=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

#print_sys_info
wall <<EOM
#Architecture : $ARCHITECTURE
#CPU physical: $PHYSICAL_CPU
#vCPU: $VIRTUAL_CPU
#Memory Usage: $MEMORY_USAGE
#Disk Usage: $DISK_USAGE
#CPU Load: $CPU_LOAD%
#Last boot: $LAST_BOOT
#LVM use: $([ $LVM_STATUS -gt 0 ] && echo "yes" || echo "no")
#Connections TCP: $ACTIVE_CONNECTIONS ESTABLISHED
#User log: $USER_COUNT
#Network: IP $IP_ADDRESS ($MAC_ADDRESS)
#Sudo: $SUDO_COMMANDS cmd
EOM

#!/bin/bash

# Check if script is run with superuser privileges
if [ "$EUID" -ne 0 ]; then
  echo "This script must be run with superuser privileges. Exiting."
  exit 1
fi

# Load the Network Block Device module
modprobe nbd

# Attach the image as a Network Block Device
qemu-nbd -c /dev/nbd0 -f raw ../test/drive.hdd

# Create a directory for mounting if it doesn't exist
mkdir -p /mnt/G

# Mount the partition from the network block device
mount /dev/nbd0p1 /mnt/G

# Optionally, you can perform operations on the mounted filesystem here

# Unmount the partition and detach the network block device
umount /mnt/G
qemu-nbd -d /dev/nbd0

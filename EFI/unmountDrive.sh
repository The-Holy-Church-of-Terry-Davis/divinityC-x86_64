if [ "$EUID" -ne 0 ]; then
  echo "This script must be run with superuser privileges. Exiting."
  exit 1
fi

sudo umount /mnt/G
sudo qemu-nbd -d /dev/nbd0
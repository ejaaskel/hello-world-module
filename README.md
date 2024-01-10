# Hello world kernel module

Simple hello world kernel module. Combines instructions from following sources:
https://tldp.org/LDP/lkmpg/2.4/html/c147.htm
https://linux-kernel-labs.github.io/refs/pull/219/merge/labs/kernel_modules.html

To build on Ubuntu, run:

```
sudo apt-get install build-essential make linux-headers-`uname -r`
make
```

To load:

```
sudo apt-get install kmod
sudo insmod hello.ko
```

Read and write oops can be demonstrated with OOPS_READ and OOPS_WRITE definitions.

Dynamic debugging can be demonstrated with the `pr_debug` calls.
To load the module with dynamic debugging enabled, run:

```
sudo insmod hello.ko dyndbg="+p"
```

To enable dynamic debugging after module has been loaded, run following (as root):

```
echo 'module hello +p' > /sys/kernel/debug/dynamic_debug/control
```

Tested on 5.15.0 kernel and Ubuntu 22.04.3 aarch64

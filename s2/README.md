# Linux Kernel Modules
## Requirements
In order to compile linux device drivers on your system you must install linux-headers with the following command:

```sh
sudo apt-get install linux-headers-$(uname -r)
```

If you have many versions of GCC you can use the following command to specify it in build procedure.

```sh
make CC=/usr/bin/gcc
```

After successful compaliation of kernel module you can insert it with the following command:

```sh
sudo insmod hello.ko
```

Then you can use `dmesg` to see the system logs.

```
106745.687281] hello: loading out-of-tree module taints kernel.
[106745.687321] hello: module verification failed: signature and/or required key missing - tainting kernel
[106745.688081] Hello, I am loading
```

At the end you can remove it and see its logs again.

```sh
sudo rmmod hello
```

```
[106957.018862] Goodbye, i am unloading
```

## Points

In C, functions are global by default.
The `static` keyword before a function name makes it static.
For example, below function fun() is static.

```c
static int fun(void)
{
  printf("I am a static function "); 
}
```

Unlike global functions in C,
access to static functions is restricted to the file where they are declared.
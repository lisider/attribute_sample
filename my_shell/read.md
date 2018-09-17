
- 我是谁
```c

一个简易shell

```


- 获取链接脚本

```c

ld -verbose > linker2.lds

去除 ===== 之外的部分.得到 ===== 之间的部分



```


- 在 __bss_start = .; 之前添加字段(也可以在其他的部分添加,但不是所有的部分,请自己尝试)

```c
/*1. 下面的段 16 字节对其*/
. = ALIGN(16);
/*2. 定义段 */
/*定义__initcall_start符号为当前位置,即.代表当前位置*/
__initcall_start = .;
data_ptrs   : { *(data_ptrs)   }
__initcall_end = .;
/*上述3行代码代表function_ptrs节位于__initcall_start和__initcall_end之间*/
__bss_start = .;

//16 字节对其的作用.

下面的数据都是32字节对其,如果下面的字段不16字节对其的话
会出现下面的情况
0000000000601078 D __initcall_start
0000000000601080 D hello

而 16 字节对其后,只能出现下面的情况
0000000000601080 D __initcall_start
0000000000601080 D hello


```

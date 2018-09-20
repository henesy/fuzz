# Fuzz -- A kernel fuzzer from Plan 9 space

## Dependencies

Fuzz(1) is tested on the [9front](http://9front.org) operating system and as such uses its libraries and runs against its kernels. 

Theoretically fuzz could be ported to unix using [plan9port](https://github.com/9fans/plan9port), but this would require a Plan 9 kernel in user space which doesn't really exist outside of [9vx](https://swtch.com/9vx/) which is untested in this regard.

## Building

	mk
	
## Installing

	mk install

## Usage



## Recommended reading

- http://doc.cat-v.org/plan_9/4th_edition/papers/comp
- http://doc.cat-v.org/plan_9/programming/c_programming_in_plan_9
- https://lsub.org/who/nemo/9.pdf
	- http://9.postnix.us/hist/3e/plan9_3e_kernel.tgz
- http://doc.cat-v.org/plan_9/misc/adding_a_syscall_to_plan_9/plan9_syscall_howto.pdf
- http://aiju.de/plan_9/plan9-syscalls
- http://man.cat-v.org/9front/2/intro
- http://man.cat-v.org/9front/1/syscall
	- http://mirror.postnix.us/plan9front/sys/src/cmd/syscall/
- http://mirror.postnix.us/plan9front/sys/src/libc/9syscall/
- http://lsub.org/who/nemo/9.intro.pdf
- http://fxr.watson.org/fxr/source/?v=PLAN9

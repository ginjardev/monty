## 0x19. C - Stacks, Queues - LIFO, FIFO
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it.
###### Monty byte code files
Files containing Monty byte codes usually have the .m extension. 

### Usage
To compile all files:
```
$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty

```
Usage: `monty filename`
where `filename` is the path to the file containing Monty byte code.
```
$ ./monty [filename]
```

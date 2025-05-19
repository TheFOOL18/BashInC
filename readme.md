# BashInC

## Starting BashInC
Start running BashInC using the following commands
```bash
make
./a.out
```
## Available Commands (Case sensitive)

### `&`

Use this to run the preceding command in the background

---
### `clear`

Use this function to clear everything currently on the terminal;

---
### `exit`

Use this functionto exit BahsInC

---
### `hop`

***cd*** equivalent of BachInC. It requires us to give the absolute or relative path of the directory we wish to hop to. 

We can also give multiple paths to hop into, which the BachInC executes sequentially.

Example:
```bash
hop test ..
```
The only requirement being that the directories are space separeated.

It also supports the ***".", "..", "~", "-"*** flags.

**'.' flag prints the currect directory path**.

**'..' flag prints the parent directory path**.

**'~' flag prints the home directory path**.

**'-' flag prints the previous directory path if it exists**.

---
### `reveal`
ls equivalent of BashInC. It requires us to give a command in the following order

```bash
reveal <flag1> <flag2> ...  <directory1> <direcctory2> ...
```
It supports the following flags:

**'-a' flag prints hidden directories.**

**'-l' flag prints the extra information of the directory entries.**

Any other flags gives an Invalid flag error(You can also give no flags).

The following are examples of some valid flags.
```bash
-lala
-alal
-l
-a
-ll
-aa
```

No directories can also be given, in which case the information about the present directory will be displayed.

---
### `log`
history equivalent of BachInC. It supports the 

---
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

### `clear`

Use this function to clear everything currently on the terminal;

### `exit`

Use this functionto exit BahsInC

### `hop`

***cd*** equivalent of BachInC. It requires us to give the absolute or relative path of the directory we wish to hop to. 

We can also give multiple paths to hop into, which the BachInC executes sequentially.

Example:
```bash
hop test ..
```
The only requirement being that the directories are space separeated.

It also supports the ***".", "..", "~", "-"*** flags.
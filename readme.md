# Braincube project
now in v *0.2*

## Features

## Usage

### Command Line

Use the Braincube file as a cmd argument

$ ./Braincube.exe ../examples/8x123.bc
### Instruction Set

##### Pointer instructions
- \>	increment the data pointer 
- \<	decrement the data pointer
- \+	increment the byte at the data pointer.
- \-	decrement the byte at the data pointer.
- \.	output the byte at the data pointer.
- ,	accept one byte of input, storing its value in the byte at the data pointer.
- [	if the byte at the data pointer is zero, then instead of moving the instruction pointer forward to the next command, jump it forward to the command after the matching ] command.
- ]	if the byte at the data pointer is nonzero jump it back to the command after the matching [ command.

#### Rubics cube instructions
Turn 90° clockwise: 
- F (front): the face facing the solver.
- B (back): the back face.
- R (right): the right face.
- L (left): the left face.
- U (up): the upper face.
- D (down): the face opposite to the upper face.
- | : Prefix for counter - clockwise rotation 
## Examples


## ToDo

# Braincube project
now in v *0.2*

<img width="800" alt="0_2_123" src="https://user-images.githubusercontent.com/33962683/33967271-0c2ba384-e063-11e7-8f3e-ba739ec8b4fd.PNG">

Usage Example Output

## Features

## Usage

### Command Line

Use the Braincube file as a cmd argument

`$ ./Braincube.exe ../examples/8x123.bc`
### Cube display without input
<img width="800" alt="0_2_no_input" src="https://user-images.githubusercontent.com/33962683/33967272-0c47d518-e063-11e7-94c2-4753242dbc08.PNG">
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

#### Cube faces
<img width="800" alt="sides" src="https://user-images.githubusercontent.com/33962683/33967273-0c623386-e063-11e7-8a9d-a0a2ff003ea4.PNG">

## Examples

### 4x123 filling example
`>>>>++++
[-<<<<+.>++.>+++.>>>>+>++>+++<<<< UD ]
`

../examples/8x123.bc

<img width="800" alt="0_2_123" src="https://user-images.githubusercontent.com/33962683/33967271-0c2ba384-e063-11e7-8f3e-ba739ec8b4fd.PNG">

## ToDo

# TextEditor
•	The editor has a single cursor at any place in the text including a blank line (a blank line has a newline character because every line has a newline character at the end; so a blank line is not really blank). <br />
•	When a new empty text is created, it is created with an empty line and the cursor is at the beginning of the text, that is, at the newline character of the only empty line. Text always has at least one line. <br />
•	Editor can take following operations: <br />
•	“Insert” a character before the cursor. <br />
•	“Enter” (i.e. create) a new line and the cursor moves to the new line. If the cursor was at the end of line, a new empty line is created, otherwise the current line is split into a new line starting from the character at the cursor. <br />
•	“Delete” a character at the cursor, or the end of line if the cursor is at the end of a line. Deleting an end of line is essentially concatenating the next line with the current line. No operation if the cursor is at the end of line of the last line. <br />
•	Move the cursor “Left” by a character (or to the end of line of above line if the cursor is at the beginning of a line). No operation if the cursor is the beginning of the first line. Move the cursor “Down” to the below line (beginning of the below line). No operation if the cursor is already at the last line. Move the cursor “Up” to the above line (beginning of the above line). No operation if the cursor is already at the first line. Move the cursor “Right” by a character (or to the beginning of below line if the cursor is at the end of a line). No operation if the cursor is the end of line of the last line. <br />
•	Move the cursor to “Home”, that is, beginning of the current line. No operation if the cursor is at the beginning of a line. <br />
•	Move the cursor to “End”, that is, end of line the current line. No operation if the cursor is at the end of a line. <br />
•	“Print Line” prints the current line.  <br />
•	“Print Text” prints the whole text. <br />

Sample input:
10
I a I b I c N I d I e I f a D T Q

Here first argument (10 in this case) is number of operations and the second argument is set of operations to be performed

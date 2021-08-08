#define OP_INSERT_CHAR 		'I' //Insert
#define OP_PRESSED_ENTER 	'N' //Newline
#define OP_PRESSED_DELETE 	'D' //Delete 
#define OP_PRESSED_LEFT 	'a' //Left arrow
#define OP_PRESSED_DOWN 	's' //Down arrow
#define OP_PRESSED_UP 		'w' //Up arrow
#define OP_PRESSED_RIGHT 	'd' //Right arrow
#define OP_PRESSED_HOME 	'H' //Home
#define OP_PRESSED_END 		'E' //End
#define OP_PRINT_LINE 		'P' //Print the current line
#define OP_PRINT_TEXT 		'T' //print the whole Text
#define OP_PRINT_REVERSE_PRINT	'R' //print entire text in reverse
#define OP_QUIT 		'Q' //Quit the editor

namespace TextEditor
{
	class CvTextEditor
	{
	private:
		typedef struct charNode
		{
			char character;
			struct charNode* prev;
			struct charNode* next;
		}charNode;

		typedef struct lineNode
		{
			struct lineNode* prevLine;
			struct lineNode* nextLine;
			charNode* lineHead;
		}lineNode;

		typedef struct cursor
		{
			lineNode* currLine;
			charNode* currNode;
		}cursor;

		lineNode* m_lines;
		cursor m_cursor;

		charNode* GetCharNode(char character);
		lineNode* GetLineNode();

	public:
		CvTextEditor();
		~CvTextEditor();

		void InsertCharacterBeforeCursor(char character);
		void EnterLine();

		void DeleteCharacterAtCursor();

		void MoveCursorLeft();
		void MoveCursorRight();
		void MoveCursorDown();
		void MoveCursorUp();

		void MoveCursorToBeginningOfTheLine();
		void MoverCursorToEndOfTheLine();

		void PrintCurrentLine();
		void PrintText();
		void PrintTextInReverse();

	};
}



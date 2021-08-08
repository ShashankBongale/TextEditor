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
		~CvTextEditor() {};

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
		void PrintEntireText();

	};
}

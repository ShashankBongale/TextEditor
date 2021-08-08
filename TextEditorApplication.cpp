#include <iostream>
#include "TextEditor.h"

using namespace std;

int main()
{
	TextEditor::CvTextEditor* textEditor = new TextEditor::CvTextEditor();

	int numberOfInput;
	cin >> numberOfInput;
	cout << numberOfInput << endl;

	for (int inputItr = 0; inputItr < numberOfInput; ++inputItr)
	{
		char input;
		cin >> input;

		switch (input)
		{
		case OP_INSERT_CHAR:
			cin >> input;
			textEditor->InsertCharacterBeforeCursor(input);
			break;

		case OP_PRESSED_ENTER:
			textEditor->EnterLine();
			break;

		case OP_PRESSED_DELETE:
			textEditor->DeleteCharacterAtCursor();
			break;

		case OP_PRESSED_LEFT:
			textEditor->MoveCursorLeft();
			break;

		case OP_PRESSED_RIGHT:
			textEditor->MoveCursorRight();
			break;

		case OP_PRESSED_UP:
			textEditor->MoveCursorUp();
			break;

		case OP_PRESSED_DOWN:
			textEditor->MoveCursorDown();
			break;

		case OP_PRESSED_HOME:
			textEditor->MoveCursorToBeginningOfTheLine();
			break;

		case OP_PRESSED_END:
			textEditor->MoverCursorToEndOfTheLine();
			break;

		case OP_PRINT_TEXT:
			textEditor->PrintText();
			break;

		case OP_PRINT_LINE:
			textEditor->PrintCurrentLine();
			break;

		case OP_PRINT_REVERSE_PRINT:
			textEditor->PrintTextInReverse();
			break;

		case OP_QUIT:
			delete textEditor;
			return 0;

		default: 
			cout << "Incorrect option: " << input << endl;
		}
	}

	delete textEditor;
	return 0;

}
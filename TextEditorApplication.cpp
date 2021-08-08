#include <iostream>
#include "TextEditor.h"

using namespace std;

int main()
{
	TextEditor::CvTextEditor textEditorObj;

	TextEditor::CvTextEditor *textEditorObj1 = new TextEditor::CvTextEditor();

	/*textEditorObj.InsertCharacterBeforeCursor('a');
	textEditorObj.InsertCharacterBeforeCursor('b');
	textEditorObj.InsertCharacterBeforeCursor('c');
	textEditorObj.InsertCharacterBeforeCursor('d');
		
	textEditorObj.MoveCursorToBeginningOfTheLine();
	textEditorObj.EnterLine();

	textEditorObj.MoveCursorUp();
	textEditorObj.MoverCursorToEndOfTheLine();

	textEditorObj.InsertCharacterBeforeCursor('e');

	textEditorObj.DeleteCharacterAtCursor();

	textEditorObj.PrintEntireText();*/

	textEditorObj.EnterLine();
	textEditorObj.InsertCharacterBeforeCursor('b');
	textEditorObj.MoveCursorUp();
	textEditorObj.DeleteCharacterAtCursor();
	//textEditorObj.InsertCharacterBeforeCursor('a');
	textEditorObj.PrintEntireText();
	//textEditorObj.PrintCurrentLine();
	
	cout << "Application End" << endl;

	return 0;
}
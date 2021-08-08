#include <iostream>
#include "TextEditor.h"

using namespace std;

namespace TextEditor
{
	CvTextEditor::CvTextEditor()
	{
		m_lines = GetLineNode();
		m_cursor.currLine = m_lines;
		m_cursor.currNode = m_lines->lineHead;
	}

	CvTextEditor::~CvTextEditor()
	{
		cout << "Quitting The Application" << endl;
	}

	CvTextEditor::charNode* CvTextEditor::GetCharNode(char character)
	{
		charNode* newCharNode = new charNode;
		newCharNode->next = NULL;
		newCharNode->prev = NULL;
		newCharNode->character = character;

		return newCharNode;
	}

	CvTextEditor::lineNode* CvTextEditor::GetLineNode()
	{
		lineNode* newLineNode = new lineNode;
		newLineNode->lineHead = GetCharNode('\n');
		newLineNode->nextLine = NULL;
		newLineNode->prevLine = NULL;

		return newLineNode;
	}

	void CvTextEditor::InsertCharacterBeforeCursor(char character)
	{
		charNode* newNode = GetCharNode(character);

		newNode->next = m_cursor.currNode;
		newNode->prev = m_cursor.currNode->prev;
		m_cursor.currNode->prev = newNode;

		if (newNode->prev == NULL)
		{
			m_cursor.currLine->lineHead = newNode;
			return;
		}

		newNode->prev->next = newNode;
		
	}

	void CvTextEditor::EnterLine()
	{
		lineNode* newLine = GetLineNode();

		newLine->prevLine = m_cursor.currLine;
		newLine->nextLine = m_cursor.currLine->nextLine;

		m_cursor.currLine->nextLine = newLine;

		if (m_cursor.currNode->next != NULL)
		{
			//When new line is inserted inbetween the  line
			newLine->lineHead = m_cursor.currNode->next;
			newLine->lineHead->prev = NULL;

			charNode* lastNode = GetCharNode('\n');
			lastNode->prev = m_cursor.currNode;

			m_cursor.currNode->next = lastNode;

			m_cursor.currLine->nextLine = newLine;
			
		}
	
		m_cursor.currLine = newLine;
		m_cursor.currNode = newLine->lineHead;
	}

	void CvTextEditor::DeleteCharacterAtCursor()
	{
		//If cursor is at the end of last line
		if (m_cursor.currNode->next == NULL && m_cursor.currLine->nextLine == NULL)
			return;

		if (m_cursor.currNode->character == '\n')
		{
			//deleting at the end of line -> concatenating two line
			lineNode* nextLine = m_cursor.currLine->nextLine;
			lineNode* currLine = m_cursor.currLine;
			charNode* currNode = m_cursor.currNode;

			if (nextLine != NULL)
			{
				currLine->nextLine = nextLine->nextLine;

				if (nextLine->nextLine != NULL)
					nextLine->nextLine->prevLine = currLine;

				nextLine->lineHead->prev = currNode->prev;

				if(currNode->prev != NULL)
					currNode->prev->next = nextLine->lineHead;
				else
				{
					currLine->lineHead = nextLine->lineHead;
				}

				m_cursor.currNode = currNode->prev;
				m_cursor.currLine = currLine;

				delete currNode;
				delete nextLine;
			}
		}
		else
		{
			charNode* currNode = m_cursor.currNode;
			
			if (currNode->prev != NULL)
			{
				currNode->prev->next = currNode->next;
				m_cursor.currNode = currNode->prev;
			}
			else
			{
				m_cursor.currLine->lineHead = currNode->next;
				m_cursor.currNode = currNode->next;
			}

			currNode->next->prev = currNode->prev;

			m_cursor.currNode = currNode->prev;
			
			delete currNode;

		}
	}

	void CvTextEditor::MoveCursorLeft()
	{
		if (m_cursor.currNode->prev != NULL)
		{
			m_cursor.currNode = m_cursor.currNode->prev;
		}
		else if (m_cursor.currLine->prevLine != NULL)
		{
			m_cursor.currLine = m_cursor.currLine->prevLine;

			charNode* nodeItr = m_cursor.currLine->lineHead;
			while (nodeItr->next != NULL)
			{
				nodeItr = nodeItr->next;
			}

			m_cursor.currNode = nodeItr;
		}
		else
		{
			//Cursor is beginning of first line
		}
	}

	void CvTextEditor::MoveCursorRight()
	{
		if (m_cursor.currNode->next != NULL)
		{
			m_cursor.currNode = m_cursor.currNode->next;
		}
		else if (m_cursor.currLine->nextLine != NULL)
		{
			m_cursor.currLine = m_cursor.currLine->nextLine;
			m_cursor.currNode = m_cursor.currLine->lineHead;
		}
		else
		{
			//cursor is at the end of last line
		}
	}

	void CvTextEditor::MoveCursorToBeginningOfTheLine()
	{
		m_cursor.currNode = m_cursor.currLine->lineHead;
	}

	void CvTextEditor::MoverCursorToEndOfTheLine()
	{
		charNode* nodeItr = m_cursor.currNode;

		while (nodeItr->next != NULL)
		{
			nodeItr = nodeItr->next;
		}

		m_cursor.currNode = nodeItr;
	}

	void CvTextEditor::MoveCursorDown()
	{
		if (m_cursor.currLine->nextLine == NULL)
			return;

		m_cursor.currLine = m_cursor.currLine->nextLine;
		m_cursor.currNode = m_cursor.currLine->lineHead;
	}

	void CvTextEditor::MoveCursorUp()
	{
		if (m_cursor.currLine->prevLine == NULL)
			return;

		m_cursor.currLine = m_cursor.currLine->prevLine;
		m_cursor.currNode = m_cursor.currLine->lineHead;

	}

	void CvTextEditor::PrintCurrentLine()
	{
		charNode* nodeItr = m_cursor.currLine->lineHead;

		while (nodeItr->character != '\n')
		{
			cout << nodeItr->character;
			nodeItr = nodeItr->next;
		}

		cout << endl;
	}

	void CvTextEditor::PrintText()
	{
		lineNode* lineItr = m_lines;

		while (lineItr != NULL)
		{
			charNode* nodeItr = lineItr->lineHead;

			while (nodeItr != NULL)
			{
				cout << nodeItr->character;
				nodeItr = nodeItr->next;
			}
			
			lineItr = lineItr->nextLine;
		}
	}
	
	void CvTextEditor::PrintTextInReverse()
	{
		lineNode* lineItr = m_lines;

		while (lineItr->nextLine != NULL)
		{
			lineItr = lineItr->nextLine;
		}

		while (lineItr != NULL)
		{
			charNode* nodeItr = lineItr->lineHead;
			while (nodeItr->next != NULL)
				nodeItr = nodeItr->next;

			nodeItr = nodeItr->prev;

			while (nodeItr != NULL)
			{
				cout << nodeItr->character;
				nodeItr = nodeItr->prev;
			}

			cout << endl;

			lineItr = lineItr->prevLine;
		}
	}
	
}


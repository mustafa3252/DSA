
#include <iostream>

using namespace std;

class Node
{
public:
  long long int data;
  Node *next;
    Node (long long int data)
  {
    this->data = data;
    next = NULL;
  }
};

Node * takeInput ()
{
  int data;
  Node *head = NULL;
  Node *tail = NULL;
  cout << "Start to enter data: ";
  cin >> data;
  while (data != -1)
    {
      Node *newNode = new Node (data);
      if (head == NULL)
	{
	  head = newNode;
	  tail = newNode;
	}
      else
	{
	  tail->next = newNode;
	  tail = tail->next;
	}
      cout << "Enter new data point: ";
      cin >> data;
    }
  return head;
}

Node * insert (Node * head, int i, int data)
{
  Node *newNode = new Node (data);
  if (i == 0)
    {
      newNode->next = head;
      head = newNode;
      return head;
    }
  int counter = 0;
  Node *temp = head;
  while (temp != NULL && counter < i - 1)
    {
      temp = temp->next;
      counter++;
    }
  if (temp != NULL)
    {
      newNode->next = temp->next;
      temp->next = newNode;
      cout << "success" << endl;
    }
  return head;
}

void print (Node * head)
{
  Node *temp = head;
  while (temp != NULL)
    {
      cout << temp->data << " ";
      temp = temp->next;
    }
}

int main ()
{
  Node *head = takeInput ();
  head = insert (head, 2, 3);
  print (head);
}

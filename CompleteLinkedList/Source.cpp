#include<iostream>

struct Node
{
	int info;
	Node* next;
};
Node* newptr;
Node* start = NULL;
Node* save;
Node* prev;
char ch{ 'y' };
int choice;
int num;

Node* createNode(int num);
void display(Node* ptr);
void insertBegining();
void insertMiddle();
void insertEnd();
void deleteNode(int key);

int main()
{
	
	do
	{
		//system("CLS");
	label:
		std::cout << "\n.......MAKE A CHOICE.......\n";
		std::cout << "\n1. Insert an Element\n";
		std::cout << "\n2. Delete a Node\n";
		std::cout << "\n3. Traverse a Node\n";
		std::cout << "\n4. EXIT\n";
		std::cout << "\nEnter your choice: ";
		std::cin >> choice;
	} while (choice < 1 || choice >4);

	switch (choice)
	{
	case 1:
	{
		do {
			std::cout << "\n........Node Inserion........\n";
			std::cout << "\n1. Insert at the Begining\n";
			std::cout << "\n2. Insert at the Middle\n";
			std::cout << "\n3. Insert at the End\n";
			std::cout << "\n4. EXIT\n";
			std::cout << "\nEnter your choice: ";
			std::cin >> choice;
		} while (choice < 1 || choice>4);

		switch (choice)
		{
			
		case 1:
		{
			std::cout << "\n.....Insertin in the Begining.....\n";
			insertBegining();
			goto label;
			//break;
		}
		case 2:
		{
			std::cout << "\t......Inserting in the Middle........\n";
			if (start == NULL)
			{
				std::cout << "\n.....Sorry Linked list is Empty....";
				std::cout << "\nINSERT IN THE BEGINING (Y/N): ";
				std::cin >> ch;
				if (ch == 'Y' || ch == 'y')
				{
					insertBegining();
					goto label;
				}
				else
				{
					std::cout << "\n....THANX FOR VISITING....\n";
					exit(0);
				}
			}
			else
			{
				insertMiddle();
				goto label;
			}
			break;
		}
		case 3:
		{
			std::cout << "\t......Inserting at the End........\n";
			insertEnd();
			goto label;
			//break;
		}
		case 4:
		{
			std::cout << "\nYou did not Insert any Node.... Thanx for visiting...\n";
			exit(0);
		}
		}
		break;
	}
	case 2:
	{
		std::cout << "\n......DELETE A NODE.....\n";

		if (start == NULL)
		{
			std::cout << "\nNo Linked List found....\n";
		}
		else
		{
			std::cout << "\nDisplaying Linked List: ";
			display(start);
			std::cout << "\n";
			std::cout << "\nEnter the number you want to delete in the linked list: ";
			int n;
			std::cin >> n;
			deleteNode(n);
			std::cout << "\nLinked List after Deleting a Node: ";
			display(start);
			goto label;
		}
		break;
	}
	case 3:
	{
		break;
	}
	case 4:
	{
		std::cout << "\n.....THANX FOR YOUR VALUABLE TIME....\n";
		exit(0);
	}

	}

	return 0;
}

Node* createNode(int num)
{
	Node* ptr = new Node;
	ptr->info = num;
	ptr->next = NULL;
	return ptr;
}

void display(Node* ptr)
{
	while (ptr != NULL)
	{
		std::cout << ptr->info << "->";
		ptr = ptr->next;
	}
}

void insertBegining()
{
	ch = 'y';
	while (ch == 'Y' || ch == 'y')
	{
		std::cout << "\nEnter the number: ";
		std::cin >> num;
		newptr = createNode(num);
		if (newptr == NULL)
			std::cout << "\nNo Memory Available\n";
		else
			std::cout << "\n...New Node Created...\n";
		if (start == NULL)
			start = newptr;
		else
		{
			save = start;
			start = newptr;
			newptr->next = save;
		}
		std::cout << "\n";
		display(start);
		std::cout << "\n";
		std::cout << "\nAdd more Nodes in the Begining (Y/N): ";
		std::cin >> ch;
	}
}

void insertMiddle()
{
	do
	{
		std::cout << "\n1. Insert Before a Number\n";
		std::cout << "\n2. Insert After a number\n";
		std::cout << "\n3. EXIT\n";
		std::cout << "\nEnter your choice: ";
		std::cin >> choice;
	} while (choice < 1 || choice>2);

	switch (choice)
	{
	case 1:
	{
		std::cout << "\n....INSERTING BEFORE A NUMBER...\n";
		ch = 'y';
		while (ch == 'Y' || ch == 'y')
		{
			//int num;
			std::cout << "\nEnter the number to be inserted: ";
			std::cin >> num;
			newptr = createNode(num);
			if (newptr == NULL)
				std::cout << "\nNo Memory Available\n";
			else
				std::cout << "\n...New Node Created...\n";
			std::cout << "\nEnter the number before which you want to insert the Node: ";
			std::cin >> num;
			save = start;
			prev = start;
			while (save->info != num)
			{
				prev = save;
				save = save->next;
			}
			prev->next = newptr;
			newptr->next = save;
			std::cout << "\n";
			display(start);
			std::cout << "\n";
			std::cout << "\nAdd more Nodes (Y/N): ";
			std::cin >> ch;
		}
		break;
	}
	case 2:
	{
		std::cout << "\n...INSERTING AFTER A NUMBER...\n";
		ch = 'y';
		while (ch == 'Y' || ch == 'y')
		{
			std::cout << "\nEnter the number: ";
			std::cin >> num;
			newptr = createNode(num);
			if (newptr == NULL)
				std::cout << "\nNo Memory Available\n";
			else
				std::cout << "\n...New Node Created...\n";
			std::cout << "\nEnter the number after which you want to insert the Node: ";
			std::cin >> num;
			save = start;
			while (save->info != num)
			{
				save = save->next;
			}
			newptr->next = save->next;
			save->next = newptr;
			std::cout << "\n";
			display(start);
			std::cout << "\n";
			std::cout << "\nAdd more Nodes (Y/N): ";
			std::cin >> ch;
		}
		break;
	}
	case 3:
	{
		std::cout << "\t....THANX FOR VISITING....\n";
		exit(0);
	}


	}
}

void insertEnd()
{
	ch = 'y';
	while (ch == 'Y' || ch == 'y')
	{
		//int num;
		std::cout << "\nEnter the number: ";
		std::cin >> num;
		newptr = createNode(num);
		if (newptr == NULL)
			std::cout << "\nNo Memory Available\n";
		else
			std::cout << "\n...New Node Created...\n";
		if (start == NULL)
			start = newptr;
		else
		{
			save = start;
			while (save->next != NULL)
			{
				save = save->next;
			}
			save->next = newptr;
		}
		std::cout << "\n";
		display(start);
		std::cout << "\n";
		std::cout << "\nAdd more Nodes (Y/N): ";
		std::cin >> ch;
	}

}

void deleteNode(int key)
{
	save = start;
	prev = start;
	if (start->info == key)
	{
		start = start->next;
		delete (save);
	}
	else
	{
		while (save->info != key)
		{
			prev = save;
			save = save->next;
		}
		prev->next = save->next;
		delete(save);
	}
}
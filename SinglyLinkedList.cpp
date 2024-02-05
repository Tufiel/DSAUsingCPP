#include<iostream>
#include<conio.h>
using namespace std;

template<typename T>
struct node
{
 T value;
 struct node<T> *next;
};


template<typename T>
class SinglyLinkedList
{
    node<T> *Head;
    int totalNodes;
public:
    SinglyLinkedList()
    {
        Head = NULL;
        totalNodes = 0;
    }

    //BASIC FUNCTIONS

    bool isEmpty()//return true if link is empty else false
    {
        if(Head)
            return false;
        return true;
    }

    node<T>* traverseToEnd()//return address of last node
    {
        node<T> *temp = Head;
        while(temp->next)
            temp = temp->next;
        return temp;
    }

    node<T>* getNewNode()//return address of new node
    {
        node<T> *temp = new node<T>;
        temp->next = NULL;
        return temp;
    }

    node<T>* getPos(int pos) //return address of a passed node number
    {
        if(pos<=0 || pos>totalNodes)
            return NULL;

        node<T> *temp = Head;
            while(--pos)
                temp = temp->next;
        return temp;
    }

    //ADD NODE FUNCTIONS

    void addAtLast(T n)// add new node at last of link
    {
        totalNodes++;
        node<T> *newNode = getNewNode();
        newNode->value = n;

        if( isEmpty() ) // if link is empty then Head will point to new node
            Head = newNode;
        else
        {
            node<T> *temp = traverseToEnd();
            temp->next = newNode;
        }
    }

    void addAtBegin(T n) // adds new node at start of link i.e, updates Head
    {
        totalNodes++;
        node<T> *newNode = getNewNode();
        newNode->value = n;

        if( isEmpty() )
            Head = newNode;
        else
        {
           newNode->next = Head;
           Head = newNode;
        }

    }

    void addAtPos(int pos,T n) // add new node at specific positon
    {

    // valid position can be from 1 to totalNodes+1
        if(pos <=0 || pos>totalNodes+1 )//if passed position is invalid
            cout<<"Wrong Position "<<pos<<" entered! please enter b/w 1-"<<totalNodes+1<<endl;
        else
        {
            node<T> *newNode = getNewNode();
            newNode->value = n;

            if( isEmpty() ) // if link is empty Head will point to new node
                Head = newNode;
            else if(pos == 1) // if position is 1 i.e, add at beginning of link
            {
                newNode->next = Head; // first node pointed by new node
                Head = newNode; // update Head i.e, new node becomes first node
            }
            else// if position is not at beginning
            {
            node<T> *temp1 = getPos(pos-1);
            /*get address of position-1 node
              eg if we have three node and want to add new node at 3rd position then we need 2nd nodes position
            */
            node<T> *temp2 = temp1->next;//point to node number pos now we can add new node b/w these two
            temp1->next = newNode;
            newNode->next = temp2;
            }
            totalNodes++;

        }

    }

    // EDIT DATA FUNCTIONS

    void updateNodeData(int pos,T newData)
    {
        if( !Head )
            cout<<"Link is empty!\n";
        else if( pos <=0 || pos > totalNodes )
            cout<<"Wrong node position! enter node position b/w 1-"<<totalNodes<<endl;
        else
        {
            node<T> *temp = getPos(pos);//get address of that node
            cout<<temp->data<<" updated to "<<newData<<endl;
            temp->data = newData;//update data
        }

    }
    //OPERATIONS ON LINK
    void reverseLink()
    {
        if( !totalNodes || totalNodes==1 )//if 0 or 1 nodes no need to reverse
            return;
        else if( totalNodes == 2 )
            {
                Head->next->next = Head; // 2nd node next ptr points to first node
                Head = Head->next ;  // head points to 2nd node
                Head->next->next = NULL; //put null in next of first node
            }
        else // more than two nodes
            {
                node<T> *first = Head,*mid = Head->next,*third = Head->next->next;//point to ist,2nd and third node

                while( mid )
                {
                mid->next = first ; // next of mid points to ist node
                first = mid; // first points to 2nd node
                mid = third; // mid points to 3rd node
                if(third)
                third = third->next; //third points to 4th node
                }
                Head->next = NULL;
                Head = first;
            }

    }

     // PRINT DATA

     void printNode(int pos)
     {
         if( !Head )
         {
             cout<<"Link is empty\n";
             return;
         }
         if(pos <=0 || pos>totalNodes)
         {
             cout<<"Enter correct node number b/w 1-"<<totalNodes<<endl;
             return;
         }
         else
         {
             node<T> *temp = getPos(pos);
             cout<<temp->value<<" ";
         }
     }

     void printAllNodes()
     {
         if( !Head )
         {
             cout<<"Link is empty\n";
             return;
         }
         else
         {
             node<T> *temp = Head;
             while(temp)
             {
                cout<<temp->value<<" ";
                temp = temp->next;
             }
         }
     }

     void printAllNodesReverse()
     {
         if( !Head )
         {
             cout<<"Link is empty\n";
             return;
         }
         else
         {
             T arr[totalNodes];
             int i =0;
              node<T> *temp = Head;
             while(temp)
             {
                arr[i] = temp->value;//push into array
                temp = temp->next;
                i++;
             }
             i--;//as i is incrimented last time
             for(;i>=0;i--)//now print array from reverse order
                cout<<arr[i]<<" ";

         }
     }

     int getTotalNodes()
     {
         return totalNodes;
     }

    //DELETE NODE FUNCTIONS

    void deleteFromBeg()
    {
        if( !Head )
            cout<<"Link is empty"<<endl;
        else
        {
            node<T> *temp = Head;
            Head = Head->next;
            cout<<temp->value<<" deleted"<<endl;
            delete temp;
            totalNodes--;
        }
    }

    void deleteFromEnd()
    {
        if( !Head )
            cout<<"Link is empty"<<endl;
        else if( !Head->next ) //single node
        {
            cout<<Head->value<<" deleted"<<endl;
            delete Head;
            Head = NULL;
            totalNodes--;
        }
        else
        {

            node<T> *temp = getPos(totalNodes-1);//get address of 2nd last node
            cout<<temp->next->value<<" deleted"<<endl;
            delete (temp->next);
            temp->next = NULL;
            totalNodes--;
        }
    }

    void deleteFromSpecificPos(int pos)
    {
        if(!Head)
        {
            cout<<"Link is empty!\n";
            return;
        }

    // valid position can be from 1 to totalNodes
        if(pos <=0 || pos>totalNodes )//if passed position is invalid
            cout<<"Wrong Position "<<pos<<" entered! please enter b/w 1-"<<totalNodes<<endl;
        else
        {

            if( isEmpty() ) // if link is empty
                cout<<"Link empty\n";
            else if(pos == 1) // if position is 1
            {
                node<T> *temp = Head; // first node pointed by new node
                Head = Head->next; // update Head i.e, 2nd node becomes first node
                delete temp;
            }
            else// if position is not at beginning
            {
            node<T> *temp1 = getPos(pos-1);
            /*get address of position-1 node
              eg if we have 5 nodes and want to delete 3rd node then we need to backup addressof 2nd and 4th node
            */
            node<T> *temp2 = temp1->next->next;//point to node number pos+1 now we can delete pos node
            delete temp1->next;
            temp1->next = temp2;
            }
            totalNodes--;

        }
    }

    void deleteAllNodes()
    {
        if( Head )
        {
            node<T> *temp1 = Head->next;
        while(Head)
        {
            delete Head;
            Head = temp1;
            if(temp1)
            temp1 = temp1->next;
        }
        cout<<"All nodes deleted"<<endl;
        totalNodes = 0;
        }
    }

    ~SinglyLinkedList()
    {
        deleteAllNodes();
        cout<<"By:Tufiel\nDate:jan/2024\n";
        cout<<"\n******** THANKS FOR USING ********\n";
        getch();
    }

};

int main()
{
    int i,j,pos,n;
    SinglyLinkedList<int> link1;
    while(1)
    {

        cout<<"Enter Options:\n1. Add Node\n2.Delete Node\n3.Print Node\n4.Reverse Link\n5.Total Nodes\n6.Exit\n:";
        cin>>i;
        switch(i)
        {
        case 1:
              cout<<"\nWhere do you want to add\n1.Beginning\n2.End\n3.At a specific position\n:";
              cin>>j;
              cout<<"Enter data :";
              cin>>n;
              switch(j)
              {
              case 1:
                link1.addAtBegin(n);
                break;
              case 2:
                link1.addAtLast(n);
                break;
              case 3:
                  cout<<"\nEnter position(like to add at start enter1):";
                  cin>>pos;
                link1.addAtPos(pos,n);
                break;
              default:
                cout<<"\nWrong option entered\n";
              }

            break;

        case 2:
               cout<<"\n1.Delete from beginning\n2.Delete from end\n3.Delete specific node\n4.Delete all nodes\n:";
               cin>>j;
               switch(j)
               {
               case 1:
                link1.deleteFromBeg();
                break;

               case 2:
                link1.deleteFromEnd();
                break;

               case 3:
                cout<<"Enter node number:";
                cin>>pos;
                link1.deleteFromSpecificPos(pos);
                break;

               case 4:
                link1.deleteAllNodes();
                break;

               default:
                cout<<"\nPlease choose correct option!\n";
               }
        break;

        case 3:
                cout<<"\n1.Print Link\n2.Print specific node\n3.Print Reverse Link\n:";
                cin>>j;
                switch(j)
                {
                case 1:
                    link1.printAllNodes();
                    break;
                case 2:
                     cout<<"Enter node number:";
                     cin>>pos;
                    link1.printNode(pos);
                    break;
                case 3:
                    link1.printAllNodesReverse();
                    break;
                default:
                    cout<<"\nWrong option entered!\n";

                }

        break;

        case 4:
                 link1.reverseLink();
                 cout<<"Link reversed\n";
                 break;

        case 5:
            cout<<link1.getTotalNodes();
            break;

        case 6:
              link1.deleteAllNodes();
              return 0;

        default :
            cout<<"\nEnter correct option\n\n";

        }
        cout<<"\nPress any key to clear screen n to keep data..."<<endl;
        if('n'!=getch())
            system("cls");
    }

    return 0;
}

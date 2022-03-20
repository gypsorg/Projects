#include <iostream>
class Node{
    friend class List;
public:
    int getdata()const{
        return data;
    }
    int place;
    int data;
    Node *nextptr;

  
    
};

class LinkedList{
    
public:
    LinkedList(){
        head = 0;
    }
    void print(){
        std::cout<<"\nData\t"<<head->data;
        std::cout<<"\nPlace\t"<<head->place;
        std::cout<<"\n";
        
    }
    void Insert(int index, int value){
        Node * New= new Node();
        New->data = value;
       New-> nextptr=NULL;
        if(index < 1) {
            std::cout<<"\nposition should be >= 1.";
          }
        if(index==1){
            New->nextptr = head;
               head = New;
            
        }
        else{
            Node* temp=head;
            for (int i=1;i<index-1;i++) {
                if (temp!=NULL) {
                    temp=temp->nextptr;
                }
            }
        
        
        if(temp != NULL) {
              New->nextptr = temp->nextptr;
            temp->nextptr= New;  
            }
        }
        New -> place=0;
    }
    int Get(int index){
        Node*temp=head;
        int m=0;
        while (temp!=NULL) {
            if (m==index) {
                
                return temp->data;
            }
            m++;
            temp=temp->nextptr;
        }
        return 0;
    }
    int Length(){
        int len=0;
        Node *temp=head;
        while (temp!=NULL) {
            len++;
            temp=temp->nextptr;
        }
        return len;
    }
    void Delete(int index){
        if (index ==1 ) {
            Node *deletenode = head;
            head = head->nextptr;
            free(deletenode);
        }
        else{
            Node *temp=head;
            for (int i=1; i<index-1; i++) {
                if (temp !=NULL) {
                    temp = temp->nextptr;
                }
            }
        }
    }
    bool HasLoop(){
        while (head->nextptr!=NULL) {
            head->place=head->place+1;
            head=head->nextptr;
            if (head->place>1) {
                return true;
            }
        }
        return false;
    }
    
private:
    Node *head;
};


int main( ){
    
    LinkedList N;
    N.Insert(1, 2);
    N.Insert(2, 4);
    N.Insert(3, 6);
    N.Insert(4, 6);
    N.Insert(4, 7);
    N.print();
    int pos = N.Get(1);
    std::cout<<pos<<std::endl;
    std::cout<<"Length  of List\t"<<N.Length()<<std::endl;
    N.Delete(1);
    if (N.HasLoop()) {
        std::cout<<"\nList has loop\n";
    }
    else
        std::cout<<"Does not have loop\n";
}

#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
        int data;
        Node* next;
        Node(int info, Node* link) {
            this->data = info;
            this->next = link;
        }
};


class LinkList{
    private:
        Node* head = nullptr;
    public:
        void addHead(int item){
            Node* newItem =  new Node(item,nullptr);
            if(!head){
                
            }
        }

};


int main()
{
      

 return 0;
}








template <typename E>
class List{
private:
    class Node{
        public:
            Node(E e){
               this->e = e;
               this->last_node = nullptr;

            }
            Node* last_node;
            Node* next_node;
            E e;
    };
    Node* head;
    Node* tail;
public:


    List(){
        head=nullptr;
        tail=nullptr;
    }
    void insert(E e){
        if(head==nullptr){

            head = new Node(e);
            tail = head;
            head->last_node = head;
            head->next_node = head;
            return;
        }
        Node* node = new Node(e);
        tail->next_node = node;
        node->last_node = tail;
        node->next_node=head;
        tail =node;
            
    }



};


#ifndef LIST_H
#define LIST_H

/*
Doubly linked list
*/
template <typename Object>
class List{
    private:
        struct Node{
            Object data;
            Node *prev;
            Node *next;

            Node(const Object & d = Object { }, Node *p = nullptr, Node *n = nullptr )
                : data{d} , prev {p}, next {n} {}
            
            Node(Object && d, Node *p = nullptr, Node *n = nullptr )
                : data{std::move(d)} , prev {p}, next {n} {}
        };

    public:
        class const_iterator{
            public:
                const_iterator()
                    : current{nullptr} {}
                
                const_iterator & operator*() const{
                    return retrieve();
                }

                //prefix increment
                const_iterator & operator++() {
                    current = current->next;
                    return *this;
                }

                //postfix increment
                const_iterator operator++ (int){
                    const_iterator old = *this;
                    ++(*this);
                    return old;
                }

                //prefix decrement
                const_iterator & operator--() {
                    current = current->prev;
                    return *this;
                }

                //postfix decrement
                const_iterator operator-- (int){
                    const_iterator old = *this;
                    --(*this);
                    return old;
                }

                //use . operator it's a reference to an object
                bool operator== (const const_iterator & rhs) const{
                    return current == rhs.current;
                }

                bool operator!= (const const_iterator & rhs) const{
                    return !(*this == rhs);
                }

            protected:
                Node *current;
                Object & retrieve() const {
                    return current->data;
                };

                const_iterator(Node *p)
                    :current {p} {}

                //We want List Class to access nonpublic members
                friend class List<Object>;
        };

        class iterator : public const_iterator{
            public:
                iterator()
                    {}
                
                Object & operator*(){
                    return const_iterator::retrieve();
                };

                const Object & operator*() const{
                    return const_iterator::operator*();
                };

                //prefix increment
                iterator & operator++(){
                    this->current = this->current->next;                    
                    return *this;
                };

                //postfix increment
                iterator operator++(int){
                    iterator old = *this;
                    ++(*this);
                    return old;
                }

                //prefix decrement
                iterator & operator--(){
                    this->current = this->current->prev;                    
                    return *this;
                };

                //postfix decrement
                iterator operator--(int){
                    iterator old = *this;
                    --(*this);
                    return old;
                }

                //boolean operators are used from inhereted class

            private:
                iterator(Node *p)
                    : const_iterator{p}{}

                //We want List Class to access nonpublic members
                friend class List<Object>;
        };

    public:

        //Constructor and Big-Five
        /*
        Destructor
        Copy Constructor
        Copy Assignment Operator
        Move Constructor
        Move Assignment Operator
        */

        List() {
            init();
        }
        
        //Destructor
        ~List(){
            clear();
            delete head;
            delete tail;
        }
        
        //Copy Conctructor
        List (const List & rhs){
            init();

            //This for loop works because we have provieded iterator class
            //Also iterator class must have begin() and end() methods
            // !=, == and * operators
            //which are implemented
            for(auto & x : rhs){
                push_back(x);
            }
        }
        
        //Copy Assignment Operator
        List & operator=(const List & rhs){
            List copy = rhs;
            std::swap(*this,copy);
            return *this;
        }

        //Move Constructor
        List (List && rhs)
            :theSize{rhs.theSize}, head{rhs.head},tail{rhs.tail}{
                rhs.theSize = 0;
                rhs.head = nullptr;
                rhs.tail = nullptr;
        }

        //Move Assignment Operator
        List & operator=(List && rhs){
            std::swap(theSize, rhs.theSize);
            std::swap(head, rhs.head);
            std::swap(tail, rhs.tail);
            return *this;
        }

        iterator begin(){
            return head->next;
        }

        const_iterator begin() const{
            return head->next;
        }

        iterator end(){
            return tail;
        }
        
        const_iterator end() const{
            return tail;
        }

        int size() const{
            return theSize;
        }

        bool empty() const{
            return size() == 0;
        }

        void clear(){
            while(!empty()){
                pop_front();
            }
        }
        
        Object & front(){
            return *begin();
        }
        const Object & front() const{
            return *begin();
        }
        Object & back(){
            return *--end();
        }
        const Object & back() const{
            return *--end();
        }

        void push_front(const Object & x){
            insert(begin(),x);
        }
        void push_front(Object && x){
            insert(begin(),std::move(x));
        }
        void push_back(const Object &x){
            insert(end(),x);
        }
        void push_back(Object && x){
            insert(end(),std::move(x));
        }
        void pop_front(){
            erase(begin());
        }
        void pop_back(){
            erase(--end());
        }

        //Insertion insert x before itr
        iterator insert (iterator itr, const Object & x){
            Node *p = itr.current;
            theSize++;
            p->prev->next = new Node(x,p->prev,p);
            p->prev = p->prev->next;
            return p->prev;
        }

        iterator insert (iterator itr, Object && x){
            Node *p = itr.current;
            theSize++;
            p->prev->next = new Node(std::move(x),p->prev,p);
            p->prev = p->prev->next;
            return p->prev;
        }

        //Erase item at itr
        iterator erase(iterator itr){
            Node *p = itr.current;
            iterator retVal{p->next};
            
            p->prev->next = p->next;
            p->next->prev = p->prev;
            
            delete p;
            theSize--;

            return retVal;
        };

        //Erase items from -> to
        iterator erase(iterator from, iterator to){
            for(iterator itr = from; itr != to;){
                itr = erase(itr);
            }
            return to;
        };

    private:
        int theSize;
        Node *head;
        Node *tail;

        void init(){
            theSize = 0;
            head = new Node();
            tail = new Node();
            head->next = tail;
            tail->prev = head;
        };
};


#endif
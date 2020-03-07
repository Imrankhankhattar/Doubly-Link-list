#include <iostream>
#include<fstream>
using namespace std;
class Node
{
private:
    float data;
    Node *next;
    Node *previous;
public:
    Node(float x)
    {
        data=x;
        next=NULL;

    }
    void Set_data(float x)
    {
        data=x;
    }
    float Get_data()
    {
        return data;
    }
    void Set_next(Node *p)
    {
        next=p;
    }
    Node* Get_next()
    {
        return next;
    }
    void Display()
    {
        cout<<data<<endl;
    }
    void Set_previous(Node *p)
    {
        previous=p;
    }
    Node* Get_previous()
    {
        return previous;
    }
//distructer
    /*~Node()
    {
    cout<<"i am going to be end:  "<<data<<endl;

    }*/
};
class Link_list
{
private:
    Node *first;
    Node *previous;
    Node *last;
public:
    Link_list()
    {
        first=NULL;
        previous=NULL;
        last=NULL;
    }

    void Add_at_start(float x)
    {

        Node *temp=new Node(x);
        if(first==NULL)
        {
            last=temp;
            first=temp;
            return;
        }
        temp->Set_next(first);
        temp->Set_previous(NULL);
        first=temp;
    }

    void Display()
    {
        Node *temp=first;
        if(first==NULL)
        {

            cout<<"nothing to display........."<<endl;
            return;
        }
        while(temp->Get_next()!=NULL)
        {

            cout<<temp->Get_data()<<" <=> ";
            temp=temp->Get_next();


        }
        cout<<temp->Get_data()<<endl;

    }
    int Size_of_list()
    {
        int size=1;
        if (first==NULL)
        {
            size=0;
            return size;//cout<<size<<endl;
        }

        else
        {

            Node *temp=first;
            while(temp->Get_next()!=NULL)
            {

                temp=temp->Get_next();
                size++;
            }
            return size;//cout<<size<<endl;
        }
    }

   void Add_at_end(float x)
    {
        if(first==NULL)
        {
            Node *temp=new Node(x);
            temp->Set_next(first);
            temp->Set_previous(NULL);
            first=temp;
            cout<<"Node added at index no 1......"<<endl;
            return;

        }

        Node *atend=new Node(x);
        Node *temp=first;
        while(true)
        {
            if(temp->Get_next()==NULL)
            {
                //cout<<"ok"<<endl;
                temp->Set_next(atend);
                atend->Set_next(NULL);
                atend->Set_previous(temp);
                return;
            }
            temp=temp->Get_next();
        }
    }
    void Remove_from_start()
    {
        if(first==NULL)
        {

            cout<<"No node to delete..."<<endl;
            return;
        }
        first=first->Get_next();
        first->Set_previous(NULL);
    }
    void Remove_from_end()
    {
        {
            if(first==NULL)
            {

                cout<<"Add node first  to delete..."<<endl;
                return;
            }
            if(first->Get_next()==NULL)
            {

                first=NULL;
                cout<<"Node deleted..."<<endl;

                return;
            }

            //Node *end=new Node(x);
            Node *temp=first;
            while(true)
            {
                if(temp->Get_next()->Get_next()==NULL)
                {
                    //cout<<"ok"<<endl;
                    temp->Set_next(NULL);//temp->Set_next(end);
                    return;
                }
                temp=temp->Get_next();
            }
        }
    }
    void Add_at_index(int index_no,float y)
    {
        if(first==NULL||index_no==1)
        {
            Add_at_start(y);

            cout<<"Node added at index no 1..."<<endl;
            return;
        }

        int size_l=Size_of_list();
        if(size_l<index_no)
        {
            Add_at_end(y);
            cout<<"Node added at end....."<<endl;
            return;
        }
        if(size_l==index_no)
        {
            Node *new_node=new Node(y);
            Node *temp=first->Get_next();
            Node *temp2=first;
            int z=2;
            while(z<index_no)
        {
            //temp=first;
            temp=temp->Get_next();
            temp2=temp2->Get_next();
            z++;
        }
        new_node->Set_next(temp);
        temp2->Set_next(new_node);
        new_node->Set_previous(temp2);
        temp->Set_previous(new_node);
        temp->Set_next(NULL);
        //index->Set_next(temp->Get_next()->Get_next());
        //temp->Set_next(index);
        return;

        }
        int x=2;
        Node *new_node=new Node(y);
        Node *temp=first->Get_next();
        Node *temp2=first;
        while(x<index_no)
        {
            //temp=first;
            temp=temp->Get_next();
            temp2=temp2->Get_next();
            x++;
        }
        temp2->Set_next(new_node);
        new_node->Set_next(temp);
        new_node->Set_previous(temp2);
        temp->Set_previous(new_node);


    }
    void Search_data(float data)
    {
        if(first==NULL)
        {

            cout<<"No data found"<<endl;
            return;
        }
        Node *temp=first;
        int n=1;
        while(temp->Get_next()!=NULL)
        {
            if(temp->Get_data()==data)
            {

                {
                    cout<<data<<"  found at index_no:"<<n<<endl;
                    return;
                }
            }
            n++;
            temp=temp->Get_next();

        }
        if(temp->Get_data()==data)
        {
            cout<<data<<"   found at index_no:"<<n<<endl;
            return;
        }
        else
            cout<<"NOT found"<<endl;


    }
    void Delete_data_node(float data)
    {
        if(first==NULL)
        {

            cout<<"Add node first to delete.."<<endl;
            return;
        }
        Node *temp=first;
        Node *temp2=first->Get_next();
        while(temp->Get_next()!=NULL)
        {
            if(temp->Get_next()->Get_data()==data)
            {

                temp->Set_next(temp->Get_next()->Get_next());
                temp2->Set_previous(temp);

                // temp->Set_next(NULL);

                return;
            }
            temp=temp->Get_next();
        }
        if(temp->Get_data()==data)
        {
            temp->Set_next(NULL);
            temp->Set_previous(temp2);
            return;
        }
        else
            cout<<"data not found at any node.."<<endl;

    }



    void Remove_at_index(int index_no)
    {

        int size_l=Size_of_list();

        if(first==NULL)
        {

            cout<<"Add node first to delete..."<<endl;
            return;
        }
        if(index_no<=0||size_l<index_no)
        {
            cout<<"Node number does not exists.Enter valid node number..."<<endl;
            return;
        }


        if(size_l==index_no)
        {
            //Node *index=new Node(y);
            Node *temp=first->Get_next();
            Node *temp2=first;
            int z=2;
            while(z<index_no)
        {
            //temp=first;
            temp=temp->Get_next();
            temp2=temp2->Get_next();
            z++;
        }
          temp2->Set_next(NULL);
          temp2->Set_previous(temp);
          return;}
        if(index_no==1)
        {
        Remove_from_start();
        }


        int x=2;
        //Node *index=new Node(y);
        Node *temp2=first->Get_next();
        Node *temp=first;
        while(temp->Get_next()!=NULL)
        {
            if(index_no==x)
            {                //temp=first;
                //temp->Set_next(temp->Get_next()->Get_next());
                temp->Set_next(temp->Get_next()->Get_next());
                temp2->Set_previous(temp);

            }
            temp=temp->Get_next();
            x++;
        }
    }
    void Reverse_display()
    {
        if(first==NULL)
        {
            cout<<"nothing to display........."<<endl;
            return;
        }
         Node *temp=first;
         while(temp->Get_next()!=NULL)
         {

             temp=temp->Get_next();
         }

//         cout<<temp->Get_data()<<endl;
        while(temp->Get_previous()!=NULL)
        {
            cout<<temp->Get_data()<<" <=> ";

            temp=temp->Get_previous();
        }
        cout<<temp->Get_data()<<endl;

    }
    void Reverse_list()
    {
        Node *swep;
        Node *temp=first;
       // Node *temp1=previous;
        while(temp!=NULL)
        {
            swep=temp->Get_next();
            temp->Set_next(temp->Get_previous());
            temp->Set_previous(swep);
            temp=temp->Get_next();
           // cout<<temp->Get_data()<<endl;
        }
        first=temp;
        temp=temp;
        }
        //previous=first;


        //cout<<temp->Get_data()<<endl;
       // Reverse_display();

    void automator()
    {
        ifstream file;
        file.open("file.txt");
        string ch;
        float b;
        int no;
        while(!file.eof())
        {
            file>>ch;
       if(ch=="AAS")
        {
            file>>b;
            Add_at_start(b);
        }
        if(ch=="AAE")
        {
            file>>b;
            Add_at_end(b);
        }
        if(ch=="ADD")
        {
            file>>b;
            file>>no;
            Add_at_index(no,b);
        }
        if(ch=="REM")
        {
            file>>b;
           Delete_data_node(b);
        }
        if(ch=="RAI")
        {
            file>>no;
           Remove_at_index(no);
        }
        if(ch=="RAS")
        {
            Remove_from_start();
        }
        if(ch=="RAE")
        {
            Remove_from_end();
        }
        if(ch=="DIS")
        {
            Display();
        }
        if(ch=="DIR")
        {
            Reverse_display();
        }
    }
}

};
int main()
{
    Link_list obj;
    obj.Add_at_end(4.5);
    obj.Add_at_end(5.5);
    //obj.Add_at_end(6.5);
    //obj.Add_at_end(7.5);
    //obj.Add_at_end(8.5);
    //obj.Display();
    //obj.Reverse_list();
    //obj.Display();
    obj.automator();
    //obj.Add_at_start(6);
    //obj.Add_at_start(5);
    //obj.Add_at_start(4);
    //obj.Add_at_start(3);
    //obj.Add_at_start(2);
    //obj.Add_at_start(1);

    //obj.Add_at_index(6,909);
   // obj.Remove_from_end();
    //obj.Display();
    //obj.Search_data(3);
    //obj.Delete_data_node(3);
    //obj.Delete_data_node(6);
    //obj.Display();
    //obj.Remove_at_index(5);
    //obj.Remove_at_index(1);
    //obj.Reverse_display();
    //obj.Display();
    //cout<<obj.Size_of_list()<<endl;
 //   obj.automator();
   // float choice;
   /*int number;
    do
    {

        int data;
        cout<<"\t\t"<<"***********Linked_list Menu************"<<"\t\t\t"<<endl;
        cout<<"\t\t\t"<<"Press 1 for: Display"<<endl<<"\t\t\t"<<"Press 2 :for Add_at_start"<<endl;
        cout<<"\t\t\t"<< "Press 3 for: Size_of_list "<<endl<<"\t\t\t"<<"Press 4 for: Add_at_end "<<endl<<"\t\t\t"<<"Press 5 for: Remove_from_end"<<endl;
        cout<<"\t\t\t"<<"Press 6 for: Add_at_index"<<endl<<"\t\t\t"<<"Press 7 for: Search_data"<<endl<<"\t\t\t"<<"Press 8 for: Delete_data_node"<<endl;
        cout<<"\t\t\t"<<"Press 9 for: Remove_at_index"<<endl<<"\t\t\t"<<"Press 10 for: Remove_from_start"<<endl<<"\t\t\t"<<"Press 11 for: Reverse_display"<<endl;
              cout<<"\t\t\t AND Press 0 for EXIT..."<<endl;
                cout<<"\t\t*********************************************\t\t\t"<<endl;

        cin>>number;
        switch (number)
        {
        case  1:
            obj.Display();
            break;
        case  2:
            cout <<"Enter data for node:"<<endl;
            cin>>data;
            obj.Add_at_start(data);
            break;
        case 3:
            int x;
            x=obj.Size_of_list();
            cout<<x<<endl;
            break;
        case 4:
            cout <<"Enter data for node:"<<endl;
            cin>>data;
            obj.Add_at_end(data);
            break;
        case 5:
            obj.Remove_from_end();
            break;
        case 6:
            cout <<"Enter data for node:"<<endl;
            cin>>data;
            int index;
            cout<<"Enter index no:"<<endl;
            cin>>index;
            obj.Add_at_index(index,data);
            break;
        case 7:
            cout <<"Enter data to search:"<<endl;
            cin>>data;
            obj.Search_data(data);
            break;
        case 8:
            cout <<"Enter data for deleting specified node:"<<endl;
            cin>>data;
            obj.Delete_data_node(data);
            break;
        case 9:
            int ind;
            cout <<"Enter index_no for deleting node:"<<endl;
            cin>>ind;
            obj.Remove_at_index(ind);
            break;
        case 10:
            obj.Remove_from_start();
            break;
        case 11:
            obj.Reverse_display();
            break;
        //default:
          //  cout << "Error! operator is not correct";
           // break;
        }
        //cout<<"   Press ANY KEY to continue else NO..."<<endl;
        //cin>>choice;
    }
    while(number!=0);*/
    return 0;
}


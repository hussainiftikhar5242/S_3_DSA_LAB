#include<iostream>
#include <cstdlib>
#include<unistd.h> 
#include<fstream>
#include<vector>
#include<string>
#include <sstream>
#include<thread>
#include<queue>
#include<stack>
using namespace std;

struct  customerData
{
    int index;
    int height;
    string customerID;
    string firstName;
    string secondname;
    string company;
    string city;
    string country;
    string phone1;
    string phone2;
    string email;
    string date;
    string website;
    customerData *left;
    customerData *right;
    
};

class customerRecord{
    customerData *root;
    public:
        customerData *addNode(int index,string customerId,string fristName,string secondName,string company,string city,string country,string phone1,string phone2,string email,string date,string website)
        {
           customerData *record = new customerData(); 
           record->index=index;
           record->customerID=customerId;
           record->firstName=fristName;
           record->secondname=secondName;
           record->company=company;
           record->city=city;
           record->country=country;
           record->phone1=phone1;
           record->phone2=phone2;
           record->email=email;
           record->date=date;
           record->website=website;
           record->left=NULL;
           record->right=NULL;
           return record;
        }
        customerData *createNode(int index,string customerId,string fristName,string secondName,string company,string city,string country,string phone1,string phone2,string email,string date,string website)
        {
            customerData *record = new customerData(); 
            record->index=index;
            record->customerID=customerId;
            record->firstName=fristName;
            record->secondname=secondName;
            record->company=company;
            record->city=city;
            record->country=country;
            record->phone1=phone1;
            record->phone2=phone2;
            record->email=email;
            record->date=date;
            record->website=website;
            record->left=NULL;
            record->right=NULL;
            return record;
        }
        bool insert(customerData *node)
        {
            customerData *prev = root;
            customerData *next = root;
            if (root == NULL)
            {
                root = node;
                return false;
            }
            while (node->index != prev->index && next != NULL)
            {
                prev = next;
                if (node->index < prev->index)
                    next = prev->left;
                else
                    next = prev->right;
            }
            if (node->index == prev->index)
            {
                delete node;
                return true;
            }
            else if (node->index > prev->index)
                prev->right = node;
            else
                prev->left = node;
            return false;
        }
        bool search1(int value)
        {
            customerData *temp = root;
            if (root == NULL)
            {
                return false;
            }
            while (temp != NULL)
            {
                if (temp->index == value)
                {
                    cout<<"Enter Updated CustomerId: ";
                    cin>>temp->customerID;
                    cout<<"ENter Updated First Name: ";
                    cin>>temp->firstName;
                    cout<<"Enter updated second Name: ";
                    cin>>temp->secondname;
                    cout<<"ENter updated company: ";
                    cin>>temp->company;
                    cout<<"Enter updated City: ";
                    cin>>temp->city;
                    cout<<"Enter updated Country: ";
                    cin>>temp->country;
                    cout<<"ENter  updated phone 1: ";
                    cin>>temp->phone1;
                    cout<<"ENter updated Phone 2: ";
                    cin>>temp->phone2;
                    cout<<"ENter updated Email: ";
                    cin>>temp->email;
                    cout<<"ENter updated date: ";
                    cin>>temp->date;
                    cout<<"ENter updated Website: ";
                    cin>>temp->website;
                    return true;
                }
                if (value < temp->index)
                    temp = temp->left;
                else
                    temp = temp->right;
            }
            return false;
        }
        bool search(int value)
        {
            customerData *temp = root;
            if (root == NULL)
            {
                return false;
            }
            while (temp != NULL)
            {
                if (temp->index == value)
                {
                    cout<<"Index: "<<temp->index<<endl;
                    cout<<"Customer Id: "<<temp->customerID<<endl;
                    cout<<"First Name: "<<temp->firstName<<endl;
                    cout<<"second Name: "<<temp->secondname<<endl;
                    cout<<"company: "<<temp->company<<endl;
                    cout<<"City: "<<temp->city<<endl;
                    cout<<"country: "<<temp->country<<endl;
                    cout<<"Phone1: "<<temp->phone1<<endl;
                    cout<<"Phone2: "<<temp->phone2<<endl;
                    cout<<"Email : "<<temp->email<<endl;
                    cout<<"date: "<<temp->date<<endl;
                    cout<<"website : "<<temp->website<<endl;
                    return true;
                }
                if (value < temp->index)
                    temp = temp->left;
                else
                    temp = temp->right;
            }
            return false;
        }
        bool deleteValue(int val)
        {
            customerData *prev = root;
            customerData *next = root;
            while (next != NULL && next->index != val)
            {
                prev = next;
                if (next->index > val)
                {
                    next = prev->left;
                }
                else
                {
                    next = prev->right;
                }
            }
            if (next == NULL)
            {
                return false;
            }
            else if (next->left == NULL && next->right == NULL)
            {
                if (prev->left == next)
                {
                    prev->left = NULL;
                }
                else
                {
                    prev->right = NULL;
                }
                delete next;
                return true;
            }
            else if (next->left == NULL || next->right == NULL)
            {
                customerData *currnode;
                if (next->left == NULL)
                {
                    currnode = next->right;
                }
                else
                {
                    currnode = next->left;
                }
                if (prev == NULL)
                {
                    delete next;
                    root = currnode;
                    return true;
                }
                if (next == prev->left)
                {
                    prev->left = currnode;
                }

                else
                {
                    prev->right = currnode;
                }
                delete next;
            }
            else
            {
                customerData *p = NULL;
                customerData *temp;
                temp = next->right;
                while (temp->left != NULL)
                {
                    p = temp;
                    temp = temp->left;
                }
                if (p != NULL)
                {
                    p->left = temp->right;
                }
                else
                {
                    next->right = temp->right;
                }
                next->index = temp->index;
                delete temp;
            }
            return true;
        }
        void bfs()
        {
            queue<customerData *> q;
            q.push(root);
            while (!q.empty())
            {
                customerData *temp = q.front();
                q.pop();
                cout << temp->index << ", ";
                if (temp->left != NULL)
                q.push(temp->left);
                if (temp->right != NULL)
                q.push(temp->right);
            }

        }
        void preOrder()
        {
            stack<customerData *> stack;
            stack.push(root);
            while (!stack.empty())
            {
                customerData * curr = stack.top();
                stack.pop();
                cout << curr->index << " ";
                if(curr->right != NULL)
                stack.push(curr->right);
                if(curr->left != NULL)
                stack.push(curr->left);
            }
        }
        void postOrder()
        {
            stack<customerData *> s1, s2;
            s1.push(root);
            while(!s1.empty())
            {
                customerData * curr = s1.top();
                s2.push(curr);
                s1.pop();
                if(curr->left != NULL)
                s1.push(curr->left);
                if(curr->right != NULL)
                s1.push(curr->right);
            }
            while (!s2.empty())
            {
                cout << s2.top()->index << " ";
                s2.pop();
            }
        }
        void inOrder()
        {
            stack<customerData *> stack;
            customerData *curr = root;
            while (!stack.empty() || curr != NULL)
            {
                if (curr != NULL)
                {
                    stack.push(curr);
                    curr = curr->left;
                }
                else
                {
                    curr = stack.top();
                    stack.pop();
                    cout << curr->index << " ";
                    curr = curr->right;
                }
            }
        }
        void addNewRecord(customerRecord &obj)
        {
            int index;
            string customerID;
            string firstName;
            string secondname;
            string company;
            string city;
            string country;
            string phone1;
            string phone2;
            string email;
            string date;
            string website;
            cout<<"Enter Index: ";
            cin>>index;
            cout<<"ENter CustomerId: ";
            cin>>customerID;
            cout<<"ENter First Name: ";
            cin>>firstName;
            cout<<"ENter second Name: ";
            cin>>secondname;
            cout<<"ENter company: ";
            cin>>company;
            cout<<"Enter City: ";
            cin>>city;
            cout<<"Enter Country: ";
            cin>>country;
            cout<<"ENter phone 1: ";
            cin>>phone1;
            cout<<"ENter Phone 2: ";
            cin>>phone2;
            cout<<"ENter Email: ";
            cin>>email;
            cout<<"ENter date: ";
            cin>>date;
            cout<<"ENter Website: ";
            cin>>website;
            obj.insert(obj.addNode(index,customerID,firstName,secondname,company,city,country,phone1,phone2,email,date,website));
        }
        void updateRecord()
        {
            int value;
            cout<<"Enter Value you want to update: ";
            cin>>value;
            if(search1(value))
            {
                cout<<"Record Updated: ";
            }
        }
        
        



};
int menu()
{
    cout<<"1. Binary Search Tree "<<endl;
    cout<<"2. AVL "<<endl;
    cout<<"3. Break "<<endl;
    cout<<"Your Option: ";
    int option;
    cin>>option;
    return option;
}
int loadMenu()
{
    cout<<"1. Load 100 Records "<<endl;
    cout<<"2. Load 1000 Records "<<endl;
    cout<<"3. Load 10000 Records "<<endl;
    cout<<"4. Load 100000 Records "<<endl;
    cout<<" Back: ";
    cout<<"Your Option:  ";
    int option=0;
    cin>>option;
    return option;

}

string parseData(string record, int field)
{
    int comma = 1;
    string item = "";
    for(int x = 0; x < record.length(); x++)
    {
    if (record[x] == ',')
    {
    comma++;
    }
    else if (comma == field)
    {
    item = item + record[x];
    }
    }
    return item;
}

void load100Record(string path,customerRecord &object)
{
    fstream myFile;
    myFile.open(path,ios::in);
    string line;
    int index;
    string customerID;
    string firstName;
    string secondname;
    string companyName;
    string city;
    string country;
    string phone1;
    string phone2;
    string email;
    string date;
    string website;
    int count=0;
    while(!(myFile.eof()))
    {
        customerData* temp2=new customerData();
        getline(myFile,line);
        if(count == 0)
        {
            count=1;
        }
        else
        {
            string a=parseData(line,1);
            stringstream s(a);
            s>>index;
            customerID=parseData(line,2);
            firstName=parseData(line,3);
            secondname=parseData(line,4);
            companyName=parseData(line,5);
            city=parseData(line,6);
            country=parseData(line,7);
            phone1=parseData(line,8);
            phone2=parseData(line,9);
            email=parseData(line,10);
            date=parseData(line,11);
            website=parseData(line,12);
            object.insert(object.addNode(index,customerID,firstName,secondname,companyName,city,country,phone1,phone2,email,date,website));

        }

    }

}
int bstMenu()
{
    cout<<endl;
    cout<<"1. Add New Record " <<endl;
    cout<<"2. Retrieve A Record "<<endl;
    cout<<"3. Update A Record "<<endl;
    cout<<"4. Delete a Record "<<endl;
    cout<<"5. Traversal " <<endl;
    cout<<"6. Back " <<endl;
    cout<<" Your Option ";
    int option=0;
    cin>>option;
    return option;
}
int searchMenu()
{
    cout<<endl;
    cout<<"1. Breath First Traversal: "<<endl;
    cout<<"2. Preorder Traversal: "<<endl;
    cout<<"3. Postorder Traversal: "<<endl;
    cout<<"4. Inorder  Traversal: "<<endl;
    cout<<"5. Back: "<<endl;
    cout<<"Your Option: "<<endl;
    int option;
    cin>>option;
    return option;
}
int main()
{
    customerRecord obj;
    int option=0;
    while(true)
    {
        option=menu();
        bst:if(option == 1)
        {
            int bstOption=loadMenu();
            if(bstOption == 1)
            {
                string path="customers-100.csv";
                load100Record(path,obj);
            }
            else if(bstOption == 2)
            {
                string path="customers-1000.csv";
                load100Record(path,obj);
            }
            else if(bstOption == 3)
            {
                string path="customers-10000.csv";
                load100Record(path,obj); 
            }
            else if(bstOption == 4)
            {
                string path="customers-100000.csv";
                load100Record(path,obj);
            }
            else if(bstOption == 5)
            {
                goto bst;
            }
            bstMenu1:while (true)
            {
                bstOption=bstMenu();
                if(bstOption == 1)
                {
                    obj.addNewRecord(obj);
                }
                else if(bstOption == 2)
                {
                    int value;
                    cout<<" Enter Index of the customer: "<<endl;
                    cin>>value;
                    if(obj.search(value))
                    {
                        cout<<"-----------------------------------------------------------------------"<<endl;
                        cout<<" Record Found "<<endl;
                    }
                    else
                    {
                        cout<<"-----------------------------------------------------------------------"<<endl;
                        cout<<" Record Not found "<<endl;
                    }   
                }
                else if(bstOption == 3)
                {
                    obj.updateRecord();
                }
                else if(bstOption == 4)
                {
                    int value;
                    cout<<"Enter Index of Customer you want to delete: ";
                    cin>>value;
                    if(obj.deleteValue(value))
                    {
                        cout<<" Delete Sucessfully ";
                    }
                    else
                    {
                        cout<<"not Found ";
                    }
                } 
                else if(bstOption == 5)
                {
                    while(true)
                    {
                        bstOption=searchMenu();
                        if(bstOption == 1)
                        {
                            obj.bfs();
                        }
                        else if(bstOption == 2)
                        {
                            obj.preOrder();
                        }
                        else if(bstOption == 3)
                        {
                            obj.postOrder();
                        }
                        else if(bstOption == 4)
                        {
                            obj.inOrder();
                        }
                        else if(bstOption == 5)
                        {
                            goto bstMenu1;
                        }
                        else
                        {
                            continue;
                        }

                    }
                }
                else if(bstOption == 6)
                {
                    goto bst;
                }
                else
                {
                    continue;
                }
            }

        }
        else if(option == 2)
        {
            int bstOption=loadMenu();
            if(bstOption == 1)
            {
                string path="customers-100.csv";
                load100Record(path,obj);
            }
            else if(bstOption == 2)
            {
                string path="customers-1000.csv";
                load100Record(path,obj);
            }
            else if(bstOption == 3)
            {
                string path="customers-10000.csv";
                load100Record(path,obj); 
            }
            else if(bstOption == 4)
            {
                string path="customers-100000.csv";
                load100Record(path,obj);
            }
            else if(bstOption == 5)
            {
                goto bst;
            }
            bstMenu1:while (true)
            {
                bstOption=bstMenu();
                // if(bstOption == 1)
                // {
                //     obj.addNewRecord(obj);
                // }
                else if(bstOption == 2)
                {
                    int value;
                    cout<<" Enter Index of the customer: "<<endl;
                    cin>>value;
                    if(obj.search(value))
                    {
                        cout<<"-----------------------------------------------------------------------"<<endl;
                        cout<<" Record Found "<<endl;
                    }
                    else
                    {
                        cout<<"-----------------------------------------------------------------------"<<endl;
                        cout<<" Record Not found "<<endl;
                    }   
                }
                else if(bstOption == 3)
                {
                    obj.updateRecord();
                }
                else if(bstOption == 4)
                {
                    int value;
                    cout<<"Enter Index of Customer you want to delete: ";
                    cin>>value;
                    if(obj.deleteValue(value))
                    {
                        cout<<" Delete Sucessfully ";
                    }
                    else
                    {
                        cout<<"not Found ";
                    }
                } 
                else if(bstOption == 5)
                {
                    while(true)
                    {
                        bstOption=searchMenu();
                        if(bstOption == 1)
                        {
                            obj.bfs();
                        }
                        else if(bstOption == 2)
                        {
                            obj.preOrder();
                        }
                        else if(bstOption == 3)
                        {
                            obj.postOrder();
                        }
                        else if(bstOption == 4)
                        {
                            obj.inOrder();
                        }
                        else if(bstOption == 5)
                        {
                            goto bstMenu1;
                        }
                        else
                        {
                            continue;
                        }

                    }
                }
                else if(bstOption == 6)
                {
                    goto bst;
                }
                else
                {
                    continue;
                }
            }

        }

        
    }

}
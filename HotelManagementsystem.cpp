#include<bits/stdc++.h>
using namespace std;

class Hotel{
    private:
        struct Node{
            int id;
            string name, room_type,date;
            Node* next;
        };

    public:
        Node* head = NULL;
        void insert();
        void menu();
        void update();
        void search();
        void deleteItem();
        void sort();
        void show();
};

void Hotel::menu(){
    int choice;
    cout<<"\n";
    cout<<"\tWelcome To Hotel Management System Application\n"<<endl;
    cout<<"\n\t********Hotel Management System********"<<endl;
    cout<<"\nS.No     Function                      Description"<<endl;
    cout<<"\n1\t Allocate Room\t\t\tInsert New Room";
    cout<<"\n2\t Search Room\t\t\tSearch Room with RoomId";
    cout<<"\n3\t Update Room\t\t\tUpdate Room Records";
    cout<<"\n4\t Delete Room\t\t\tDelete Room with RoomId";
    cout<<"\n5\t Show Room Records\t\tShow room Records that we added";
    cout<<"\n6\t Exit"<<endl;

    while(true) {
        cout<<"Enter Your choice"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                insert();
                break;
            case 2:
                search();
                break;
            case 3:
                update();
                break;
            case 4:
                deleteItem();
                break;
            case 5:
                show();
                break;

            case 6:
                exit(0);
            default:
                cout<<"Invalid, Please choose correct options."<<endl;
                continue;
        }
    }
}
void Hotel::insert(){
    cout<<"\n\t_________Hotel Management System_________";
    Node* new_Node = new Node;
    new_Node->next = NULL;  // Initialize the next pointer
    cout<<"\n Enter Room Id : "<<endl;
    cin>>new_Node->id;
    cout<<"\n Enter Customer First Name : "<<endl;
    string firstName;
    cin>>firstName;
    cout<<"\n Enter Customer Last Name : "<<endl;
    string lastName;
    cin>>lastName;
    new_Node->name = firstName + " " + lastName;
    while (true) {
        cout << "\n Enter Allocated Date (DD/MM/YYYY) : ";
        string day, month, year;
        cin >> day >> month >> year;
        new_Node->date = day + "/" + month + "/" + year;
        
        if (atoi(day.c_str()) > 31) {
            cout << "Day must be between 1 and 31." << endl;
            continue;
        }
        if (atoi(month.c_str()) > 12) {
            cout << "Month must be between 1 and 12." << endl;
            continue;
        }
        if (atoi(year.c_str()) > 2024) {
            cout << "Year must be between 1900 and 2024." << endl;
            continue;
        }
        break; // Exit the loop if the date is valid
    }
     while (true) {
        cout << "\n Enter Room Type(Single/Double/Twin) : ";
        cin >> new_Node->room_type;
        if (new_Node->room_type == "Single" || new_Node->room_type == "Double" || new_Node->room_type == "Twin") {
            break; // Exit the loop if the room type is valid
        }
        cout << "Please mention from the correct option." << endl;
    }

    if(head==NULL){
        head = new_Node;
    }
    else{
        Node* ptr = head;
        while(ptr->next!= NULL){
            ptr = ptr->next;
        }
        ptr->next = new_Node;
    }
    cout<<"\n\n\t\t New Room Inserted";
    menu();
}

void Hotel::search(){
    cout<<"\n\t_________Hotel Management System_________";
    int t_id;

    if(head==NULL){
        cout<<"\n\nLinked list is empty";
    }
    else{
        cout<<"\n\n Room ID : ";
        cin>>t_id;
        Node* ptr = head;
        while(ptr!=NULL){
            if(t_id == ptr->id){
                cout<<"\n\nRoom ID : "<<ptr->id;
                cout<<"\n\nCustomer Name : "<<ptr->name;
                cout<<"\n\nRoom Allocated Date : "<<ptr->date;
                cout<<"\n\nRoom Type : "<<ptr->room_type<<endl;
                return;  // Return after finding the room
            }
            ptr = ptr->next;  // Move to the next node
            menu();
        }
        cout<<"\nRoom not found"<<endl;  // If room not found
    }
}

void Hotel::update(){
    cout<<"\n\t_________Hotel Management System_________";
    int t_id;
    if(head==NULL){
        cout<<"\n\nLinked list is Empty";
    }
    else{
        cout<<"\n\nWhich room ID you should update: ";
        cin>>t_id;
        Node *ptr = head;
        while(ptr!=NULL){
            if(t_id==ptr->id){
                cout<<"\n\nEnter your new room ID : ";
                cin>>ptr->id;

                cout<<"\n\nCustomer First Name : ";
                string firstName;
                cin>>firstName;
                cout<<"\n\nCustomer Last Name : ";
                string lastName;
                cin>>lastName;
                ptr->name = firstName + " " + lastName;

                cout<<"\n\nAllocated Date (DD/MM/YYYY) : ";
                cin>>ptr->date;

                cout<<"\n\nRoom Type (Single/Double/Twin) : ";
                cin>>ptr->room_type;

                cout<<"\n\n\t\t Updated Record Successfully";
                menu();
                return;  // Return after updating the room
            }
            ptr = ptr->next;  // Move to the next node
        }
        cout<<"\nRoom not found";  // If room not found
    }
}

void Hotel::deleteItem(){
    cout<<"\n\t_________Hotel Management System_________";
    int t_id;
    if(head==NULL){
        cout<<"\n\nLinked list is Empty";
    }
    else{
        cout<<"\n\nWhich room ID you want to delete : ";
        cin>>t_id;
        if(t_id==head->id){
            Node* ptr = head;
            head = head->next;
            delete ptr;
            cout<<"Delete Room Record Successfully\n";
        }
        else {
            Node* prev = head;
            Node* ptr = head;
            while(ptr!=NULL){
                if(t_id==ptr->id){
                    prev->next = ptr->next;
                    delete ptr;
                    cout<<"Delete Room Record Successfully\n";
                    menu();
                    return;  // Return after deleting the room
                }
                prev = ptr;
                ptr = ptr->next;
            }
            cout<<"\nRoom not found";  // If room not found
        }
    }
}

void Hotel::show(){
    Node* ptr = head;
    while(ptr!=NULL){
        cout<<"\n\nRoom ID : "<<ptr->id;
        cout<<"\n\nCustomer Name : "<<ptr->name;
        cout<<"\n\nAllocated Date : "<<ptr->date;
        cout<<"\n\nRoom Type : "<<ptr->room_type;
        ptr = ptr->next;
        menu();
    }
}

void Hotel::sort(){
    if(head==NULL){
        cout<<"\n\nLinked list is Empty";
        menu();
    }

    int count=0, t_id;
    string t_name, t_roomtype,t_date;
    Node* ptr = head;
    while(ptr!=NULL){
        count++;
        ptr = ptr->next;
    }
    for(int i=1; i<=count; i++){
        Node* ptr = head;
        for(int j=1; j<=count-1; j++){  // Fixed loop condition
            if(ptr->id > ptr->next->id){
                t_id = ptr->id;
                t_name = ptr->name;
                t_date = ptr->date;
                t_roomtype = ptr->room_type;
                // Save data into current node
                ptr->id = ptr->next->id;
                ptr->name = ptr->next->name;
                ptr->date = ptr->next->date;
                ptr->room_type = ptr->next->room_type;
                // Save data into next node
                ptr->next->id = t_id;
                ptr->next->name = t_name;
                ptr->next->date = t_date;
                ptr->next->room_type = t_roomtype;
            }
            ptr = ptr->next;  // Move to the next node
        }
    }
}

int main(){
    Hotel h;
    h.menu();
}



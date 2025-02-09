#include<iostream>
using namespace std;
class Book{
    private:
    string book_name;
    string ISBN;
    string author_name;
    string publisher;
    public:
    //constructer
    Book(string book_name, string ISBN, string author_name, string publisher){
        this->book_name = book_name;
        this->ISBN = ISBN;
        this->author_name = author_name;
        this->publisher = publisher;
    }
    void getBookInfo(){
        cout<<"Book Name: "<<book_name<<endl;
        cout<<"ISBN: "<<ISBN<<endl;
        cout<<"Author Name: "<<author_name<<endl;
        cout<<"Publisher: "<<publisher<<endl;
    }
};
int main(){
    Book book[5] = {Book("The Great Gatsby", "9780743273565", "F. Scott Fitzgerald", "Scribner"),
        Book("To Kill a Mockingbird", "9780061120084", "Harper Lee", "J.B. Lippincott & Co."),
        Book("1984", "9780451524935", "George Orwell", "Secker & Warburg"),
        Book("Moby-Dick", "9781503280786", "Herman Melville", "Harper & Brothers"),
        Book("Pride and Prejudice", "9781503290563", "Jane Austen", "T. Egerton")};
        for(int i=0;i<5;i++){
            cout<<"Book: "<<(i+1)<<endl;
            book[i].getBookInfo();
        }

    return 0;
}
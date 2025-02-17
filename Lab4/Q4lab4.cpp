#include<iostream>
using namespace std;

class Book{
    private:
        string author;
        string title;
        float price;
        string publisher;
        int stock_pos;
    public:
        Book(string author, string title, float price, string publisher, int stock_pos){
            this->author = author;
            this->title = title;
            this->price = price;
            this->publisher = publisher;
            this->stock_pos = stock_pos;
        }

        bool isMatch(string auth, string ttl){
            return (author == auth && title == ttl);
        }

        void DisplayBook(){
            cout << "Author: " << author << endl;
            cout << "Title: " << title << endl;
            cout << "Price: " << price << endl;
            cout << "Publisher: " << publisher << endl;
            cout << "Stock Position: " << stock_pos << endl;
        }

        void requestCopies(int req_copies){
            if(stock_pos >= req_copies){
                cout<<"Requested copies are available."<<endl;
                stock_pos -= req_copies;
                double total = price * req_copies;
                cout << "Total cost: $" << total << endl;
            }
            else {
                cout << "Not enough copies available." << endl;
            }
        }
};

int main(){
     Book inventory[] = {
        Book("J.K. Rowling", "Harry Potter and the Sorcerer's Stone", 20.99, "Bloomsbury", 10),
        Book("George Orwell", "1984", 15.99, "Secker & Warburg", 5),
        Book("Harper Lee", "To Kill a Mockingbird", 12.99, "J.B. Lippincott & Co.", 8)
    };

    string searchTitle, searchAuthor;
    int requestedCopies;

    // Get user input for search
    cout << "Enter the title of the book: ";
    getline(cin, searchTitle);
    cout << "Enter the author of the book: ";
    getline(cin, searchAuthor);

     bool found = false;
    for (Book& book : inventory) {
        if (book.isMatch(searchTitle, searchAuthor)) {
            found = true;
            book.DisplayBook();

            // Get the number of copies required
            cout << "Enter the number of copies required: ";
            cin >> requestedCopies;

            // Process the purchase
            book.requestCopies(requestedCopies);
            break;
        }
    }

    if (found == false) {
        cout << "The book is not available in the inventory." << endl;
    }
    return 0;
}
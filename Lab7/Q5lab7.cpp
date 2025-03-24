#include <iostream>
#include <vector>
using namespace std;

// Base class: Media
class Media {
protected:
    string title, publicationDate, publisher;
    int uniqueID;
public:
    Media(string t, string pubDate, int id, string pub) : title(t), publicationDate(pubDate), uniqueID(id), publisher(pub) {}
    virtual void displayInfo() {
        cout << "Title: " << title << "\nPublication Date: " << publicationDate
             << "\nUnique ID: " << uniqueID << "\nPublisher: " << publisher << "\n";
    }
    virtual void checkOut() { cout << title << " checked out.\n"; }
    virtual void returnItem() { cout << title << " returned.\n"; }
    string getTitle() { return title; }
    string getPublicationDate() { return publicationDate; }
};

// Derived class: Book
class Book : public Media {
    string author, ISBN;
    int numberOfPages;
public:
    Book(string t, string pubDate, int id, string pub, string a, string isbn, int pages)
        : Media(t, pubDate, id, pub), author(a), ISBN(isbn), numberOfPages(pages) {}
    void displayInfo() override {
        Media::displayInfo();
        cout << "Author: " << author << "\nISBN: " << ISBN << "\nPages: " << numberOfPages << "\n";
    }
};

// Derived class: DVD
class DVD : public Media {
    string director;
    int duration;
    float rating;
public:
    DVD(string t, string pubDate, int id, string pub, string dir, int dur, float rat)
        : Media(t, pubDate, id, pub), director(dir), duration(dur), rating(rat) {}
    void displayInfo() override {
        Media::displayInfo();
        cout << "Director: " << director << "\nDuration: " << duration << " mins\nRating: " << rating << "\n";
    }
};

// Derived class: CD
class CD : public Media {
    string artist, genre;
    int numberOfTracks;
public:
    CD(string t, string pubDate, int id, string pub, string art, int tracks, string gen)
        : Media(t, pubDate, id, pub), artist(art), numberOfTracks(tracks), genre(gen) {}
    void displayInfo() override {
        Media::displayInfo();
        cout << "Artist: " << artist << "\nTracks: " << numberOfTracks << "\nGenre: " << genre << "\n";
    }
};

// Function Overloading for Searching
void searchMedia(vector<Media*> &library, string title) {
    for (Media* media : library) {
        if (media->getTitle() == title) {
            cout << "\nMedia Found:\n";
            media->displayInfo();
            return;
        }
    }
    cout << "\nMedia not found.\n";
}

void searchMedia(vector<Media*> &library, int year) {
    bool found = false;
    for (Media* media : library) {
        if (stoi(media->getPublicationDate()) == year) {
            cout << "\nMedia Found:\n";
            media->displayInfo();
            found = true;
        }
    }
    if (!found) cout << "\nNo media found from year " << year << ".\n";
}

int main() {
    vector<Media*> library;
    
    library.push_back(new Book("C++ Programming", "2020", 101, "Tech Books", "Bjarne Stroustrup", "12345", 500));
    library.push_back(new DVD("Inception", "2010", 102, "Warner Bros", "Christopher Nolan", 148, 8.8));
    library.push_back(new CD("Thriller", "1982", 103, "Epic Records", "Michael Jackson", 9, "Pop"));
    
    cout << "Library Collection:\n--------------------\n";
    for (Media* media : library) {
        media->displayInfo();
        cout << "--------------------\n";
    }
    
    // Search Example
    searchMedia(library, "Inception");
    searchMedia(library, 2020);
    
    // Cleaning up dynamically allocated memory
    for (Media* media : library) {
        delete media;
    }
    
    return 0;
}

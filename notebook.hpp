#ifndef NOTEBOOK_HPP
#define NOTEBOOK_HPP

#include <iostream>
#include <string>
#include <vector>

// Note

class Note {
private:
  std::string title_;
  std::string body_;

public:
  // Constructors
  Note() : title_("Untitled"), body_("") {}
  Note(const std::string &title, const std::string &body)
      : title_(title), body_(body) {}

  // Accessors
  std::string getTitle() const { return title_; }
  std::string getBody() const { return body_; }

  // Mutators
  void setTitle(const std::string &t) { title_ = t; }
  void setBody(const std::string &b) { body_ = b; }

  // Member functions
  virtual void display();
  virtual std::string serialize() {
    return "[Note]\n" + title_ + "\n" + body_ + "\n";
  }
};

// EncryptedNote

class EncryptedNote : public Note {
private:
  std::string password_;

public:
  // Default Constructor
  EncryptedNote() : Note(), password_(""){};
  // Copy Constructor
  EncryptedNote(const std::string &title, const std::string &body,
                const std::string &password)
      : Note(title, body), password_(password) {}

  // Member Functions
  virtual void display() override;
  virtual std::string serialize() override {
    return "[EncNote]\n" + getTitle() + "\n" + getBody() + "\n" + password_ +
           "\n";
  }
};

// Notebook

class Notebook {
private:
  // A vector of pointers is used to allow for polymorphism between note and
  // encrypted note.
  std::vector<Note *> notes_;

public:
  int getSize() const { return notes_.size(); }
  // Returns a pointer to a Note objet
  Note *getNote(const int &index) const { return notes_[index]; }
  void addNote(Note *newNote) { notes_.push_back(newNote); };
  // Displays note titles in a list
  void listNotes() const;
  // Displays title and body of note of given index
  void viewNote(const int& index) const;
  // Exports notes to a new file given by the user
  void saveNotes(const std::string &notesFilename) const;
  // Loads notes from given file into notes_ 
  void loadNotes(const std::string &notesFilename);

  Notebook() = default;
};

// ask user to provide a note
Note *createNote();
EncryptedNote *createEncryptedNote();

#endif

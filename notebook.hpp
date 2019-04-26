#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include <iostream>
#include <vector>

struct Note {
  std::string title_, body_;
  Note() = default;
  Note(std::string newTitle, std::string newBody)
      : title_(newTitle), body_(newBody){};
};

class Notebook {
private:
  std::vector<Note> list_;

public:
  size_t size() const { return list_.size(); }
  // Member Functions
  void addNote(const Note &newNote); // adds new Note to list_
  void remove(const size_t &index) { list_.erase(list_.begin() + index); }
  void listNotes() const;            // lists Notes
  void viewNote(const size_t &index); // displays contents of a specific note
  void
  saveNotes(const std::string &filename); // exports notes to a specified text file
  void loadNotes(const std::string &filename); // imports notes from specified txt file
  Note operator[](const size_t &i) { return list_[i]; }
};

#endif

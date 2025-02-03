#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <QString>

class Node {
public:
    QString word;
    QString arabicMeaning;
    Node* next;

    Node(const QString& w, const QString& m) : word(w), arabicMeaning(m), next(nullptr) {}
};

class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    void insert(const QString& word, const QString& arabicMeaning);
    bool search(const QString& word, QString& arabicMeaning) const;
    bool remove(const QString& word);
    QString getAllWords() const;

private:
    Node* head;
};

#endif


#include "linkedlist.h"

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void LinkedList::insert(const QString& word, const QString& arabicMeaning) {
    Node* newNode = new Node(word, arabicMeaning);

    if (!head || word < head->word) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next && current->next->word < word) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

bool LinkedList::search(const QString& word, QString& arabicMeaning) const {
    Node* current = head;
    while (current) {
        if (current->word == word) {
            arabicMeaning = current->arabicMeaning;
            return true;
        }
        current = current->next;
    }
    return false;
}

bool LinkedList::remove(const QString& word) {
    if (!head) return false;

    if (head->word == word) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    Node* current = head;
    while (current->next) {
        if (current->next->word == word) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            return true;
        }
        current = current->next;
    }
    return false;
}

QString LinkedList::getAllWords() const {
    QString result;
    Node* current = head;
    while (current) {
        result += current->word + ": " + current->arabicMeaning + "\n";
        current = current->next;
    }
    return result;
}


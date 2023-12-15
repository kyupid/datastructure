package org.example;


import org.junit.jupiter.api.Test;

class SingleLinkedListTest {

    @Test
    void test() {
        SingleLinkedList<String> list = new SingleLinkedList<>();
        list.insertAtHead("1");
        list.insertAtHead("2");
        list.insertAtHead("3");
        list.insertAtHead("4");
    }
}
package org.example;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class DoubleLinkedListTest {
    @Test
    void test() {
        DoubleLinkedList<String> list = new DoubleLinkedList<>();

        list.insertAtTail("1");
        list.insertAtTail("2");
        list.insertAtTail("3");
        System.out.println(list);
    }
}
package org.example;

public class SingleLinkedList<T> {

    private Node<T> head;
    private int size;

    public void insertAtHead(T data) {
        if (head == null) {
            head = new Node<>();
            head.data = data;
            size++;
            return;
        }

        Node<T> temp = head.next;
        while (temp != null) {

        }

        if (head.next == null) {
            head.next.data = data;
            return;
        }


    }

    public void insertAtTail() {

    }

    public void find() {

    }

    public void delete() {

    }

    public void print() {

    }

    public int size() {
        return this.size;
    }

    private static class Node<T> {
        T data;
        Node next;
    }
}

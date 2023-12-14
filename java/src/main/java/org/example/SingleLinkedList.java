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
        if (head.next != null) {
            Node<T> temp2 = new Node<>();
            temp2 = head.next;

            Node<T> temp = new Node<>();
            temp.data = data;
            head.next = temp;
            head.next.next = temp2;
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
        Node<T> next;

    }
}

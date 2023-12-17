package org.example;

import java.util.Objects;

public class Queue<T> {
    /**
     * Enqueue: Adds a new element to the queue. This action typically involves adding an element to the end of the queue.
     * Dequeue: Removes and returns an element from the queue. This action usually involves removing an element from the front of the queue, adhering to the 'FIFO' (First-In, First-Out) principle.
     * Peek or Front: Returns the element at the front of the queue without removing it. This method is useful for inspecting the first element of the queue.
     * IsEmpty: Checks if the queue is empty. This method returns true when there are no elements in the queue.
     * Size or Length: Returns the number of elements in the queue.
     */
    private Node<T> head;
    private int size;

    public void enqueue(T data) { // 포인터가 1개라 InsertAtTail 방식
        if (size == 0) {
            head = new Node<>(data);
        } else if (size > 0) {
            Node<T> prev = head;
            Node<T> temp = head.next;
            while (temp != null) {
                prev = temp;
                temp = temp.next;
            }
            prev.next = new Node<>(data);
        }
        size++;
    }

    public T dequeue() {
        if (size > 0) {
            Node<T> temp = head;
            head = head.next;
            size--;
            return temp.data;
        }
        return null;
    }

    public T peek() {
        if (head == null) {
            return null;
        }
        return head.data;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public int size() {
        return size;
    }

    private static class Node<T> {
        T data;
        Node<T> next;

        public Node(T data) {
            this.data = data;
        }

        @Override
        public String toString() {
            return "data: " + data;
        }

        // find 할때 data가지고 비교하기 위함
        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Node<?> node = (Node<?>) o;
            return Objects.equals(data, node.data);
        }

        // find 할때 data가지고 비교하기 위함
        @Override
        public int hashCode() {
            return Objects.hash(data);
        }
    }
}

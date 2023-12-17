package org.example;

import java.util.NoSuchElementException;
import java.util.Objects;

public class Stack<T> {

    /**
     * push(element): 스택의 맨 위에 요소를 추가합니다. 이 함수는 스택에 새로운 요소를 넣는 데 사용됩니다.
     * pop(): 스택의 맨 위 요소를 제거하고 반환합니다. 이 함수는 스택에서 가장 최근에 추가된 요소를 제거할 때 사용됩니다.
     * peek() 또는 top(): 스택의 맨 위 요소를 반환하지만 제거하지는 않습니다. 이것은 현재 스택의 맨 위에 어떤 요소가 있는지 확인할 때 유용합니다.
     * isEmpty(): 스택이 비어 있는지 여부를 확인합니다. 이 함수는 스택에 요소가 있는지 없는지를 확인할 때 사용됩니다.
     * size(): 스택에 저장된 요소의 개수를 반환합니다. 이것은 스택의 크기를 알고 싶을 때 사용할 수 있습니다.
     */
    private Node<T> head;
    private int size;

    public void push(T data) {
        if (size == 0) {
            head = new Node<>(data);
        } else if (size > 0) {
            Node<T> newNode = new Node<>(data);
            newNode.next = head;
            head = newNode;
        }
        size++;
    }
    public T pop() {
        if (size > 0) {
            T temp = head.data;
            head = head.next;
            size--;
            return temp;
        }
        return null;
    }

    public T peek() {
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

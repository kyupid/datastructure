package org.example;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;

class SingleLinkedListTest {

    @Test
    @DisplayName("insertAtHead(): list 머리에 element를 담을 수 있다.")
    void insertAtHead() {
        SingleLinkedList<String> list = new SingleLinkedList<>();
        list.insertAtHead("1");
        list.insertAtHead("2");
        list.insertAtHead("3");
        list.insertAtHead("4");

        assertThat(list.size()).isEqualTo(4);
    }

    @Test
    @DisplayName("find(): 같은 객체를 찾을 수 있다.")
    void find() {
        SingleLinkedList<String> list = new SingleLinkedList<>();
        list.insertAtHead("1");
        list.insertAtHead("2");

        String found = list.find("2");
        assertThat(found).isEqualTo("2");

        String found2 = list.find("3");
        assertThat(found2).isNull();
    }

    @Test
    @DisplayName("insertAtTail(): list 꼬리에 element를 담을 수 있다.")
    void insertAtTail() {
        SingleLinkedList<String> list = new SingleLinkedList<>();
        list.insertAtTail("1");
        list.insertAtTail("2");
        list.insertAtTail("3");
        list.insertAtTail("4");

        assertThat(list.size()).isEqualTo(4);
    }
}
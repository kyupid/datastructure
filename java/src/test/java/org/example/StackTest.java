package org.example;

import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;

class StackTest {

    @Test
    void test() {
        Stack<String> stack = new Stack<>();
        stack.push("1");
        assertThat(stack.peek()).isEqualTo("1");
        stack.push("2");
        assertThat(stack.peek()).isEqualTo("2");
        stack.push("3");
        assertThat(stack.peek()).isEqualTo("3");

        assertThat(stack.size()).isEqualTo(3);
        assertThat(stack.isEmpty()).isFalse();

        String pop1 = stack.pop();
        assertThat(pop1).isEqualTo("3");
        String pop2 = stack.pop();
        assertThat(pop2).isEqualTo("2");
        String pop3 = stack.pop();
        assertThat(pop3).isEqualTo("1");

        assertThat(stack.size()).isEqualTo(0);
        assertThat(stack.isEmpty()).isTrue();
    }
}

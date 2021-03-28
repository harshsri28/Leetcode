ListNode *detectCycle(ListNode *head) {
        // edge case - empty list
        if (!head || !head->next || !head->next->next) return NULL;
        // support animals
        ListNode *turtle = head, *hare = head;
        // checking if we loop or not
        while (hare->next && hare->next->next) {
            hare = hare->next->next;
            turtle = turtle->next;
            if (hare == turtle) break;
        }
        // exiting if we do not find a loop
        if (hare != turtle) return NULL;
        // finding the start of the loop
        turtle = head;
        while (turtle != hare) {
            hare = hare->next;
            turtle = turtle->next;
        }
        return turtle;
    }
};

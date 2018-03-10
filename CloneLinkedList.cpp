Node * clone(Node *start){
	Node *cur = start, *temp;
	while(cur){
		temp = cur->next;
		cur->next = new Node(cur->data);
		cur->next->next = temp;
		cur = temp;
	}
	cur = start;
	while(cur){
		cur->next->random = cur->random->next;
		cur = cur->next?cur->next->next:cur->next;
	}
	Node *original = start;
	Node *copy = start->next;
	temp = copy; 
	while(original && copy){
		original->next = original->next?original->next->next:original->next;
		copy->next = copy->next?copy->next->next:copy->next;
		original = original ->next;
		copy = copy ->next; 
	}
	return temp; 
}
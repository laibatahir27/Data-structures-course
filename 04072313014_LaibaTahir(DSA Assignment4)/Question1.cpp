#include<iostream>
#include<string>
template<typename k, typename v>
struct node {
	std::pair<k, v>key_value;
	node<k, v>*left;
	node<k, v>*right;
	node<k, v>*parent;
	bool is_H;
	node() {
		is_H = false;
	}
};

template<typename k, typename v>
class map {
private:
	node< k, v>*H;
	int n;

	// Sucessor Function 
	node<k, v>* successor(node<k, v>* ptr) {  // go on right side and find leftmost value
		ptr = ptr->right;
		while (ptr->left != this->H) {
			ptr = ptr->left;
		}
		return ptr;
	}
	
	                                                 // Recursive functions 
    // clear_r Function
	void clear_r(node<k, v>*ptr) {
		if (ptr == this->H) {
			return;
		}
		else {
			clear_r(ptr->left);
			clear_r(ptr->right);
			delete ptr;
		}
	}

	// copy_tree Function
	void copy_tree(node<k, v>*ptr) {
		if (ptr == this->H) {
			return;
		}
		else {
			this->insert(ptr->key_value);
			copy_tree(ptr->left);
			copy_tree(ptr->right);
		}
	}

public:
	// Constructor
	map() {
		H = new node<k, v>;
		H->left = this->H;
		H->right = this->H;
		H->parent = this->H;
		H->is_H = true;
	}

	// Destructor
	~map() {
		clear();
	}

	// Clear
	void clear() {
		clear_r(this->H->parent);
		this->H->parent = this->H;
		this->H->right = this->H;
		this->H->left = this->H;
		n = 0;
	}
	// Size
	int size() const {
		return n;
	}

	// Copy Constructor
	map(const map<k, v>&other) {
		*this = other;
	}

	// Operator= Function
	map<k, v> operator=(const map<k, v>&other) {
		if (this == &other) {
			return*this;
		}
		this->clear();
		this->copy_tree(other.H->parent);
		return*this;
	}

	// Iterator Class
	class iterator {
	private:
		node<k, v>*ptr;
	public:
		friend class map;
		bool operator!=(const iterator&other)const {
			return this->ptr != other.ptr;
		}
		bool operator==(const iterator&other)const {
			return this->ptr == other.ptr;
		}
		std::pair<k, v>&operator*()const {
			return this->ptr->key_value;
		}
		std::pair<k, v>*operator->()const {
			return &(this->ptr->key_value);
		}
		iterator& operator++() {
			node<k, v>*current;
			current = this->ptr;
			if (current->right->is_H == false) {
				current = current->right;
				while (current->left->is_H == false) {
					current = current->left;
				}
			}
			else {
				node<k, v>*parent;
				parent = current->parent;
				while (parent->is_H == false && current == parent->right) {
					current = parent;
					parent = current->parent;
				}
				current = parent;
			}
			this->ptr = current;
			return*this;
		}

		iterator& operator--() {
			node<k, v>*current;
			current = this->ptr;
			if (current->left->is_H == false) {
				current = current->left;
				while (current->right->is_H == false) {
					current = current->right;
				}
			}
			else {
				node<k, v>*parent;
				parent = current->parent;
				while (parent->is_H == false && current == parent->left) {
					current = parent;
					parent = current->parent;
				}
				current = parent;
			}
			this->ptr = current;
			return*this;
		}
	};

	// Reverse Iterator Class
	class rev_iterator {
	private:
		node<k, v>*ptr;
	public:
		friend class map;
		bool operator!=(const rev_iterator&other)const {
			return this->ptr != other.ptr;
		}
		bool operator==(const rev_iterator&other)const {
			return this->ptr == other.ptr;
		}
		std::pair<k, v>&operator*()const {
			return this->ptr->key_value;
		}
		std::pair<k, v>*operator->()const {
			return &(this->ptr->key_value);
		}
		rev_iterator& operator++() {
			node<k, v>*current;
			current = this->ptr;
			if (current->left->is_H == false) {
				current = current->left;
				while (current->right->is_H == false) {
					current = current->right;
				}
			}
			else {
				node<k, v>*parent;
				parent = current->parent;
				while (parent->is_H == false && current == parent->left) {
					current = parent;
					parent = current->parent;
				}
				current = parent;
			}
			this->ptr = current;
			return*this;
		}

		rev_iterator& operator--() {
			node<k, v>*current;
			current = this->ptr;
			if (current->right->is_H == false) {
				current = current->right;
				while (current->left->is_H == false) {
					current = current->left;
				}
			}
			else {
				node<k, v>*parent;
				parent = current->parent;
				while (parent->is_H == false && current == parent->right) {
					current = parent;
					parent = current->parent;
				}
				current = parent;
			}
			this->ptr = current;
			return*this;
		}
	};

	// Begin Function
	iterator begin()const {
		iterator it;
		it.ptr = this->H->left;
		return it;
	}

	// End Function
	iterator end()const {
		iterator it;
		it.ptr = this->H;
		return it;
	}

	// rBegin Function
	iterator rbegin()const {
		iterator it;
		it.ptr = this->H->right;
		return it;
	}

	// rEnd Function
	iterator rend()const {
		iterator it;
		it.ptr = this->H;
		return it;
	}

	// Find Function
	iterator find(const k &key) {
		iterator it;
		it.ptr = this->H;
		node<k, v>*temp;
		temp = this->H->parent;

		while (temp != this->H) {
			if (key == temp->key_value.first) {
				it.ptr = temp;
				return it;
			}
			else if (key < temp->key_value.first) {
				temp = temp->left;
			}
			else {
				temp = temp->right;
			}
		}
		it.ptr = this->H;
		return it;
	}

	// Insert Function
	void insert(const std::pair<k, v>k_v) {
		node<k, v>*newNode;
		newNode = new node<k, v>;
		newNode->key_value = k_v;
		k key;
		key = k_v.first;
		newNode->left = this->H;
		newNode->right = this->H;
		if (this->H->parent == this->H) { //tree is empty
			this->H->left = newNode;
			this->H->right = newNode;
			this->H->parent = newNode;
			newNode->parent = this->H;
			n++;
		}
		else {
			node<k, v>*current;
			current = this->H->parent;
			node<k, v>*parent;
			parent = current->parent;
			while (current != this->H) {
				parent = current;
				if (key < current->key_value.first) {
					current = current->left;
				}
				else {
					current = current->right;
				}
			}
			if (key < parent->key_value.first) {
				parent->left = newNode;
			}
			else {
				parent->right = newNode;
			}
			newNode->parent = parent;
			n++;
		}
	}

	// Erase Function
	size_t erase(const k &key) {  // erase
		iterator it;
		it = this->find(key);
		if (it.ptr == this->H) {
			return 0;  // key not found
		}

		node<k, v>* current;
		current = it.ptr;
		node<k, v>* parent;
		parent = current->parent;

		if (current->left == this->H && current->right == this->H) {  // to delete leaf node
			if (current == parent->left) {
				parent->left = this->H;
			}
			else {
				parent->right = this->H;
			}
			delete current;
		}
		else if (current->left != this->H && current->right == this->H) {   // node has only left child
			if (current == parent->left) {
				parent->left = current->left;
			}
			else {
				parent->right = current->left;
			}
			current->left->parent = parent;
			delete current;
		}
		else if (current->right != this->H && current->left == this->H) {  // node has only right child
			if (current == parent->right) {
				parent->right = current->right;
			}
			else {
				parent->left = current->right;
			}
			current->right->parent = parent;
			delete current;
		}
		else {  // node has two children
			node<k, v>* succNode;
			succNode = this->successor(current);
			node<k, v>* parentSucc;
			parentSucc = succNode->parent;

			// If successor is not the right child of the current node
			if (succNode != current->right) {
				parentSucc->left = succNode->right;
				if (succNode->right != this->H) {
					succNode->right->parent = parentSucc;
				}
				succNode->right = current->right;
				current->right->parent = succNode;
			}

			// Replace current node's data with successor's data
			if (parent->left == current) {
				parent->left = succNode;
			}
			else {
				parent->right = succNode;
			}
			succNode->parent = parent;
			succNode->left = current->left;
			current->left->parent = succNode;

			delete current;
		}
		return 1;  // Successfully erased
	}

	// at Function
	v& at(const k&key) {  // at ftn
		node<k, v>*temp;
		temp = this->H->parent;

		while (temp != this->H) {
			if (key == temp->key_value.first) {
				return temp->key_value.second; // Return the value if key is found
			}
			else if (key < temp->key_value.first) {
				temp = temp->left;
			}
			else {
				temp = temp->right;
			}
		}
		throw("value not found!"); // throw exception if value not found
	}

	// Count Function
	size_t count(const k& key) const {
		node<k, v>*temp;
		temp = this->H->parent;

		while (temp != this->H) {
			if (key == temp->key_value.first) {
				return 1;
			}
			else if (key < temp->key_value.first) {
				temp = temp->left;
			}
			else {
				temp = temp->right;
			}
		}
		return 0;  // if key not found
	}

	// Contains Function
	bool contains(const k& key) const {
		node<k, v>*temp;
		temp = this->H->parent;

		while (temp != this->H) {
			if (key == temp->key_value.first) {
				return true;
			}
			else if (key < temp->key_value.first) {
				temp = temp->left;
			}
			else {
				temp = temp->right;
			}
		}
		return false;  // if key not found
	}

	// [] operator Function
	v& operator[](const k&key) {  
		node<k, v>*temp;
		temp = this->H->parent;

		while (temp != this->H) {
			if (key == temp->key_value.first) {
				return temp->key_value.second; // Return the value if key is found
			}
			else if (key < temp->key_value.first) {
				temp = temp->left;
			}
			else {
				temp = temp->right;
			}
		}
		node<k, v>*newNode;
		newNode = new node<k, v>;
		newNode->key_value.first = key;
		newNode->key_value.second = ""; // empty string
		newNode->left = this->H;
		newNode->right = this->H;
		if (this->H->parent == this->H) { //tree is empty
			this->H->left = newNode;
			this->H->right = newNode;
			this->H->parent = newNode;
			newNode->parent = this->H;
			n++;
		}
		else {
			node<k, v>*current;
			current = this->H->parent;
			node<k, v>*parent;
			parent = current->parent;
			while (current != this->H) {
				parent = current;
				if (key < current->key_value.first) {
					current = current->left;
				}
				else {
					current = current->right;
				}
			}
			if (key < parent->key_value.first) {
				parent->left = newNode;
			}
			else {
				parent->right = newNode;
			}
			newNode->parent = parent;
			n++;
		}
		return newNode->key_value.second;
	}

};

int main() {
	map<int, std::string>m1, m2;
	map<int, std::string>::iterator it;
	std::pair<int, std::string>p;  // Declares a pair object 'p' that stores an integer and a string.

	p.first = 1;  
	p.second = "Laiba"; 

	m1.insert(p);   // Calling insert Function
   std::cout << "Key 1: " << m1[1] << std::endl;  // calling [] operator function

	p.first = 2; 
	p.second = "Fatima";  

	m1.insert(p);
	std::cout << "Key 2: " << m1[2] << std::endl;

	std::cout << m1.at(1) << std::endl;  // calling at function

	std::cout << "Size of map:" << m1.size() << std::endl;  // calling size function

	if (m1.contains(2)) {  // calling contains function
		std::cout << "key found!" << std:: endl;
	}
	else {
		std::cout << "key not found!" << std::endl;
	}

	size_t result1 = m1.erase(1);  // calling erase function
	if (result1 > 0) {
		std::cout << "Successfully erased the value" << std::endl;
	}
	else {
		std::cout << "Key not found in the map." << std::endl;
	}


}
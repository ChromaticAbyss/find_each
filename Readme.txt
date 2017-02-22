Usage:
Copy KMP.h onto your project and #include it.
The namespace is find_each, as is the name of the function

find_each(
	forward iterator to beginning of long seqeuence
	forward iterator to end of long seqeuence
	forward iterator to beginning of short seqeuence
	forward iterator to end of short seqeuence
	bool = true (allow overlapping matches such as "aa" twice in "aaa") 
)
returns a vector of iterators on the long sequence, pointing to the start of each occurence

Made by Erik Messerli
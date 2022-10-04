#include <stdio.h>
#include <Python.h> //need setting path

PyObject* add(PyObject* self, PyObject* arg) {
	PyObject* a = PyTuple_GetItem(arg, 0);
	PyObject* b = PyTuple_GetItem(arg, 1);
	int a_size = PyList_Size(a);
	int b_size = PyList_Size(b);
	int size = (a_size < b_size) ? a_size : b_size;
	int a_item, b_item;
	PyObject* c_item;
	PyObject* c = PyList_New(size);
	for (int i = 0; i < size; i++) {
		a_item = PyLong_AsLong(PyList_GetItem(a, i));
		b_item = PyLong_AsLong(PyList_GetItem(b, i));
		c_item = PyLong_FromLong(a_item + b_item);
		PyList_SetItem(c, i, c_item);
	}
	return c;
};

static PyMethodDef methods[] = {
	{"add", add, METH_VARARGS},
	{NULL}
};

static struct PyModuleDef pmd = {
	PyModuleDef_HEAD_INIT,
	"hello",
	"document",
	-1,
	methods
};

PyMODINIT_FUNC PyInit_hello(void) {
	return PyModule_Create(&pmd);
};
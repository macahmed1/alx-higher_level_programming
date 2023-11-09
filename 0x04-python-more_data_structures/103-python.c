#define PY_SSIZE_T_MAX ((size_t)-1 >> 1)

void print_python_list(PyObject *p) {
    Py_ssize_t i;
    Py_ssize_t size;

    if (PyList_Check(p)) {
        size = ((PyListObject *)p)->allocated;
        printf("[*] Size of the Python List = %zd\n", size);
        printf("[*] Allocated = %zd\n", size);
        for (i = 0; i < size; i++) {
            PyObject *item = ((PyListObject *)p)->ob_item[i];
            printf("Element %zd: %s\n", i, item->ob_type->tp_name);
        }
    } else {
        fprintf(stderr, "  [ERROR] Invalid List Object\n");
    }
}

void print_python_bytes(PyObject *p) {
    Py_ssize_t i;
    Py_ssize_t size;

    if (PyBytes_Check(p)) {
        size = PyBytes_Size(p);
        printf("[.] bytes object info\n");
        printf("  size: %zd\n", size);
        printf("  trying string: %s\n", PyBytes_AsString(p));
        printf("  first 10 bytes: ");
        for (i = 0; i < size && i < 10; i++) {
            printf("%02x", (unsigned char)PyBytes_AsString(p)[i]);
            if (i < size - 1 && i < 9)
                printf(" ");
        }
        printf("\n");
    } else {
        fprintf(stderr, "  [ERROR] Invalid Bytes Object\n");
    }
}


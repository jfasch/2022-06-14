def create_print_function(message):
    def print_function():
        print(message)
    return print_function

p = create_print_function('hallo joerg')
print(p.__closure__)
p()

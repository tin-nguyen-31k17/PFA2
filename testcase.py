import random

# Generate a test case for a single knight
def generate_knight():
    hp = random.randint(1, 999)
    level = random.randint(1, 10)
    phoenixdown = random.randint(0, 5)
    gil = random.randint(1, 999)
    antidote = random.randint(0, 5)
    return f"{hp} {level} {phoenixdown} {gil} {antidote}"

# Generate test cases for knights
def generate_knights_testcases(num_testcases):
    testcases = []
    for _ in range(num_testcases):
        num_knights = random.randint(1, 1000)
        knights_info = [generate_knight() for _ in range(num_knights)]
        testcase = f"{num_knights}\n" + "\n".join(knights_info)
        testcases.append(testcase)
    return testcases

# Generate test cases for events
def generate_events_testcases(num_testcases):
    testcases = []
    for _ in range(num_testcases):
        num_events = random.randint(1, 1000)
        events = " ".join(str(random.randint(1, 99)) for _ in range(num_events))
        testcase = f"{num_events}\n{events}"
        testcases.append(testcase)
    return testcases

# Generate 100 test cases for knights and events
knights_testcases = generate_knights_testcases(10000)
events_testcases = generate_events_testcases(10000)

# Save the test cases to files
for i in range(10000):
    with open(f"testcase_{i+1}_knights.txt", "w") as f:
        f.write(knights_testcases[i])
    with open(f"testcase_{i+1}_events.txt", "w") as f:
        f.write(events_testcases[i])

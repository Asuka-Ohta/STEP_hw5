def readNumber(line, index):
    number = 0
    while index < len(line) and line[index].isdigit():
        number = number * 10 + int(line[index])
        index += 1
    if index < len(line) and line[index] == '.':
        index += 1
        keta = 0.1
        while index < len(line) and line[index].isdigit():
            number += int(line[index]) * keta
            keta *= 0.1
            index += 1
    token = {'type': 'NUMBER', 'number': number}
    return token, index


def readPlus(line, index):
    token = {'type': 'PLUS'}
    return token, index + 1


def readMinus(line, index):
    token = {'type': 'MINUS'}
    return token, index + 1


def readMulti(line, index):
    token = {'type': 'MULTI'}
    return token, index + 1


def readDivide(line, index):
    token = {'type': 'DIVIDE'}
    return token, index + 1


def tokenize(line):
    tokens = []
    index = 0
    while index < len(line):
        if line[index].isdigit():
            (token, index) = readNumber(line, index)
        elif line[index] == '+':
            (token, index) = readPlus(line, index)
        elif line[index] == '-':
            (token, index) = readMinus(line, index)
        elif line[index] == '*':
            (token, index) = readMulti(line, index)
        elif line[index] == '/':
            (token, index) = readDivide(line, index)
        else:
            print 'Invalid character found: ' + line[index]
            exit(1)
        tokens.append(token)
    return tokens


def evaluate1(tokens): # Multi and Divide
    tokens2 = []
    tokens.insert(0, {'type': 'PLUS'}) # Insert a dummy '+' token
    index = 0
    while index < len(tokens):
        answer = 0
        if tokens[index]['type'] == 'NUMBER':
            if tokens[index - 1]['type'] == 'MULTI':
                answer = tokens[index-2]['number'] * tokens[index]['number']
                token = {'type': 'NUMBER', 'number': answer}
            elif tokens[index - 1]['type'] == 'DIVIDE':
                answer = tokens[index-2]['number'] / tokens[index]['number']
                token = {'type': 'NUMBER', 'number': answer}
            else:
                token = tokens[index]
            index += 1
            tokens2.append(token)
    return tokens2

def evaluate2(tokens): # Plus and Minus
    answer = 0
    tokens.insert(0, {'type': 'PLUS'}) # Insert a dummy '+' token
    index = 1
    while index < len(tokens):
        if tokens[index]['type'] == 'NUMBER':
            if tokens[index - 1]['type'] == 'PLUS':
                answer += tokens[index]['number']
            elif tokens[index - 1]['type'] == 'MINUS':
                answer -= tokens[index]['number']
            else:
                print 'Invalid syntax'
        index += 1
    return answer


while True:
    print '> ',
    line = raw_input()
    tokens = tokenize(line)
    answer = evaluate2(evaluate1(tokens))
    print "answer = %f\n" % answer

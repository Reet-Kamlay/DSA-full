int parenthesisMatch(char *exp)
{
    struct stack *s;
    s->size = 100;
    s->top = -1;
    s->arr = (struct stack *)malloc(s->size * sizeof(char));
    char popped_ch;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(s, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(s))
            {
                return 0;
            }
            popped_ch = pop(s);
            if (!match(popped_ch, exp[i]))
            {
                return 0;
            }
        }
    }
    if (isEmpty(s))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int match(char a, char b)
{
    if (a == '(' &&b = ')')
    {
        return 1;
    }
    if (a == '[' &&b = ']')
    {
        return 1;
    }
    if (a == '{' &&b = '}')
    {
        return 1;
    }
    return 0;
}
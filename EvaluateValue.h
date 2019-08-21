class EvaluateValue
{
private:
    char to;
    char from;
    float rate;
    int time;
public:
    EvaluateValue(char* input_str);
    void Printall();
    ~EvaluateValue();
    float Calculate();
};
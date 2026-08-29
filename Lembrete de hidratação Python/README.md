# 💧 Lembrete de Hidratação

Um aplicativo Python simples e eficaz que envia notificações periódicas lembrando você de se hidratar ao longo do dia, com mensagens personalizadas baseadas no seu perfil.

## 📋 Descrição

Este programa calcula sua necessidade diária de água com base na sua massa corporal e nível de atividade física, enviando lembretes a cada hora para garantir que você mantenha uma hidratação adequada.

## ✨ Funcionalidades

- 📊 Cálculo personalizado da necessidade hídrica diária
- 🔔 Notificações desktop com som a cada hora
- 💬 Mensagens motivacionais aleatórias
- 👤 Personalização com o nome do usuário
- 🏃 Três níveis de atividade física

## 🛠️ Requisitos

- Python 3.6+
- Biblioteca `notifypy`

## 📦 Instalação

1. Clone este repositório:
```bash
git clone https://github.com/seu-usuario/lembrete-hidratacao.git
cd lembrete-hidratacao
```

2. Instale as dependências:
```bash
pip install notify-py
```

3. Certifique-se de ter a estrutura de pastas correta:
```
projeto/
├── main.py
├── data/
│   └── hydration_phrases.json
└── media/
    ├── image/
    │   └── drinking-water-icon.png
    └── audio/
        └── notify.wav
```

## 📄 Configuração do JSON

Crie o arquivo `data/hydration_phrases.json` com frases motivacionais:

```json
{
  "frases_hidratacao": [
    "Seu corpo agradece cada gole! 💧",
    "Hidratação é saúde! Beba água agora! 🌊",
    "Mantenha-se hidratado para manter o foco! 💪",
    "Água é vida! Não se esqueça de beber! 🚰",
    "Que tal um copo de água fresquinha? 🥤"
  ]
}
```

## 🚀 Como Usar

1. Execute o programa:
```bash
python main.py
```

2. Responda às perguntas:
   - Digite seu nome
   - Informe sua massa corporal em kg
   - Selecione seu nível de atividade física:
     - [1] Sedentário (30ml/kg)
     - [2] Moderadamente ativo (35ml/kg)
     - [3] Ativo (40ml/kg)

3. O programa calculará sua necessidade diária de água e começará a enviar notificações a cada hora.

## 📊 Cálculo da Necessidade Hídrica
```ascii
| Nível de Atividade  | ml por kg |
|---------------------|-----------|
| Sedentário          | 30 ml/kg  |
| Moderadamente Ativo | 35 ml/kg  |
| Ativo               | 40 ml/kg  |
```
**Exemplo:** Uma pessoa de 70kg moderadamente ativa precisa de 70 × 35 = 2.450ml (2,5 litros) por dia.

## 🎨 Personalização

### Alterar o Intervalo de Notificações

No código, modifique a linha:
```python
time.sleep(60 * 60)  # 1 hora em segundos
```

Para 30 minutos, use:
```python
time.sleep(60 * 30)  # 30 minutos
```

### Adicionar Novas Frases

Edite o arquivo `hydration_phrases.json` e adicione suas próprias mensagens motivacionais.

## 🤝 Contribuindo

Contribuições são bem-vindas! Sinta-se à vontade para:

1. Fazer um Fork do projeto
2. Criar uma branch para sua feature (`git checkout -b feature/NovaFuncionalidade`)
3. Commit suas mudanças (`git commit -m 'Adiciona nova funcionalidade'`)
4. Push para a branch (`git push origin feature/NovaFuncionalidade`)
5. Abrir um Pull Request

## 📝 Licença

Este projeto está sob a licença MIT. Veja o arquivo [LICENSE](LICENSE) para mais detalhes.

## 👨‍💻 Autor

Nícolas - [@Nicolinux-dev](https://github.com/Nicolinux-dev)

## 🙏 Agradecimentos

- Biblioteca [notify-py](https://github.com/ms7m/notify-py) para as notificações desktop
- Comunidade Python pela inspiração

---

⭐ Se este projeto foi útil para você, considere dar uma estrela!

💧 Mantenha-se hidratado!
